#include <iostream>
#include <string>
#include "hooks.hpp"
#include "wrapper.hpp"
#include <Windows.h>
#include <easyhook.h>

extern "C" void __declspec(dllexport) __stdcall NativeInjectionEntryPoint(REMOTE_ENTRY_INFO* remote_info);

bool hook(void* original, void* hook)
{
	HOOK_TRACE_INFO hHook = { NULL };
	NTSTATUS result = LhInstallHook(
		original,
		hook,
		NULL,
		&hHook);
	if (FAILED(result))
	{
		std::wstring error = RtlGetLastErrorString();
		//std::wcout << L"[MazeHooks] Failed to install hook: " << error << std::endl;
		return false;
	}
	else
	{
		//std::wcout << L"[MazeHooks] Hook installed successfully." << std::endl;
		ULONG ACLEntries[1] = { 0 };
		LhSetExclusiveACL(ACLEntries, 1, &hHook);
		return true;
	}
}

void allocate_console()
{
	winapi::process::alloc_console();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
}

void* find_module(std::wstring target_module)
{
	auto process = winapi::process::get_current_process();
	auto modules = winapi::module::enum_process_modules(process);
	
	for (auto module : modules)
	{
		auto module_name = winapi::module::get_module_file_name_ex(
			process,
			module);

		if (module_name.find(target_module) != std::string::npos)
		{
			return module;
		}
	}
	
	return nullptr;
}

void hook_debug_log(void* game_assembly, int offset)
{
	auto debug_log = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto debug_log_ptr = reinterpret_cast<void*>(debug_log);
	std::cout << "[HOOKS] UnityEngine::DebugLog @ " << debug_log_ptr << std::endl;
	hooks::unity_engine::original_debug_log = reinterpret_cast<
		hooks::types::debug_log_t>(
			debug_log_ptr);
	hook(debug_log_ptr, hooks::unity_engine::debug_log_hook);
}

void hook_send_emoji(void* game_assembly, int offset)
{
	auto send_emoji = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto send_emoji_ptr = reinterpret_cast<void*>(send_emoji);
	std::cout << "[HOOKS] ServerManager::SendEmoji @ " << send_emoji_ptr << std::endl;
	hooks::server_manager::original_send_emoji = reinterpret_cast<
		hooks::types::send_emoji_t>(
			send_emoji_ptr);
	hook(send_emoji_ptr, hooks::server_manager::send_emoji_hook);
}

void hook_process_jump(void* game_assembly, int offset)
{
	auto process_jump = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto process_jump_ptr = reinterpret_cast<void*>(process_jump);
	std::cout << "[HOOKS] CharacterController::ProcessJump @ " << process_jump_ptr << std::endl;
	hooks::character_controller::original_process_jump = reinterpret_cast<
		hooks::types::process_jump_t>(
			process_jump_ptr);
	hook(process_jump_ptr, hooks::character_controller::process_jump_hook);
}

void hook_get_character_state(void* game_assembly, int offset)
{
	auto get_character_state = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto get_character_state_ptr = reinterpret_cast<void*>(get_character_state);
	std::cout << "[HOOKS] CharacterStateController::get @ " << get_character_state_ptr << std::endl;
	hooks::character_controller::original_get_character_state = reinterpret_cast<
		hooks::types::get_character_state_t>(
			get_character_state_ptr);
	hook(get_character_state_ptr, hooks::character_controller::get_character_state);
}

void hook_update_server_position(void* game_assembly, int offset)
{
	auto update_server_position = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto update_server_position_ptr = reinterpret_cast<void*>(update_server_position);
	std::cout << "[HOOKS] ServerManager::UpdateServerPosition @ " << update_server_position_ptr << std::endl;
	hooks::server_manager::original_update_server_position = reinterpret_cast<
		hooks::types::update_server_position_t>(
			update_server_position_ptr);
	hook(update_server_position_ptr, hooks::server_manager::update_server_position_hook);
}

void hook_send(void* game_assembly, int offset)
{
	auto send = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto send_ptr = reinterpret_cast<void*>(send);
	std::cout << "[HOOKS] UdpClient::Send @ " << send_ptr << std::endl;
	hooks::udp_client::original_send = reinterpret_cast<
		hooks::types::send_t>(
			send_ptr);
	hook(send_ptr, hooks::udp_client::send_hook);
}

void hook_send_data(void* game_assembly, int offset)
{
	auto send_data = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto send_data_ptr = reinterpret_cast<void*>(send_data);
	std::cout << "[HOOKS] ServerManager::SendData @ " << send_data_ptr << std::endl;
	hooks::server_manager::original_send_data = reinterpret_cast<
		hooks::types::send_data_t>(
			send_data_ptr);
	hook(send_data_ptr, hooks::server_manager::send_data_hook);
}

void hook_set_position(void* game_assembly, int offset)
{
	auto set_position = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto set_position_ptr = reinterpret_cast<void*>(set_position);
	std::cout << "[HOOKS] NpcController::SetPosition @ " << set_position_ptr << std::endl;
	hooks::npc_controller::original_set_position = reinterpret_cast<
		hooks::types::set_position_t>(
			set_position_ptr);
	hook(set_position_ptr, hooks::npc_controller::set_position_hook);
}

void hook_set_emitting(void* game_assembly, int offset)
{
	auto set_emitting = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto set_emitting_ptr = reinterpret_cast<void*>(set_emitting);
	std::cout << "[HOOKS] TrailRenderer::SetEmitting @ " << set_emitting_ptr << std::endl;
	hooks::trail_renderer::original_set_emitting = reinterpret_cast<
		hooks::types::set_emitting_t>(
			set_emitting_ptr);
	hook(set_emitting_ptr, hooks::trail_renderer::set_emitting_hook);
}

void hook_update(void* game_assembly, int offset)
{
	auto update = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto update_ptr = reinterpret_cast<void*>(update);
	std::cout << "[HOOKS] ServerManager::Update @ " << update_ptr << std::endl;
	hooks::server_manager::original_update = reinterpret_cast<
		hooks::types::update_t>(
			update_ptr);
	hook(update_ptr, hooks::server_manager::update_hook);
}

void hook_new_position(void* game_assembly, int offset)
{
	auto new_position = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto new_position_ptr = reinterpret_cast<void*>(new_position);
	std::cout << "[HOOKS] NpcController::NewPosition @ " << new_position_ptr << std::endl;
	hooks::npc_controller::original_new_position = reinterpret_cast<
		hooks::types::new_position_t>(
			new_position_ptr);
	hook(new_position_ptr, hooks::npc_controller::new_position_hook);
}

void hook_send_heartbeat(void* game_assembly, int offset)
{
	auto send_heatbeat = reinterpret_cast<std::intptr_t>(game_assembly) + offset;
	auto send_heatbeat_ptr = reinterpret_cast<void*>(send_heatbeat);
	std::cout << "[HOOKS] ServerManager::SendHeartbeat @ " << send_heatbeat_ptr << std::endl;
	hooks::server_manager::original_send_heartbeat = reinterpret_cast<
		hooks::types::send_heartbeat_t>(
			send_heatbeat_ptr);
	hook(send_heatbeat_ptr, hooks::server_manager::send_heartbeat_hook);
}

void __stdcall NativeInjectionEntryPoint(REMOTE_ENTRY_INFO* remote_info)
{
	allocate_console();
	auto game_assembly = find_module(L"GameAssembly.dll");
	std::cout << "[HOOKS] GameAssembly.dll @ " << game_assembly << std::endl;
	hook_debug_log(game_assembly, 0x5FF1A0);
	hook_send_emoji(game_assembly, 0x85BFB0);
	hook_process_jump(game_assembly, 0x843B50);
	//hook_get_character_state(game_assembly, 0x232830);
	hook_update_server_position(game_assembly, 0x85B980);
	hook_send(game_assembly, 0x67B780);
	hook_send_data(game_assembly, 0x85C110);
	hook_set_position(game_assembly, 0x83F4C0);
	hook_set_emitting(game_assembly, 0x4F01A0);
	hook_update(game_assembly, 0x85E170);
	hook_new_position(game_assembly, 0x83F5A0);
	hook_send_heartbeat(game_assembly, 0x85C560);
}