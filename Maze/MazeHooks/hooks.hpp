#pragma once
#include "ipc.hpp"
#include <Windows.h>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <vector>
#include "wrapper.hpp"
#include "detail.hpp"

namespace hooks
{
    class types
    {
    public:
        struct il2cpp_class_t;
        struct il2cpp_object_t
        {
            il2cpp_class_t* klass;
            void* monitor;
        };
        struct vector3_t
        {
            float x;
            float y;
            float z;
        };
        struct color_t
        {
            float r;
            float g;
            float b;
            float a;
        };
        struct surface_t
        {
            void* klass;
            void* monitor;
            void* tagName;
            float controlMultiplier;
            float speedMultiplier;
            color_t color;
        };
        struct byte_array_t 
        {
            il2cpp_object_t obj;
            void* bounds;
            uintptr_t max_length;
            uint8_t m_Items[65535];
        };
        struct string_t 
        {
            string_t* klass;
            void* monitor;
            int32_t m_stringLength;
            wchar_t m_firstChar[1];
        };
        struct quaternion_t
        {
            float x;
            float y;
            float z;
            float w;
        };

        class message_t
        {
        public:
            void* some_object;
            uint64_t reserved;
            uint32_t message_size;
            wchar_t message[0];
        };
        class orthonormal_reference_t
        {
        public:
            vector3_t forward;
            vector3_t up;
            vector3_t right;
        };
        class planar_movement_parameters_t
        {
        public:
            void* klass;
            void* monitor;
            float speed;
            float boostMultiplier;
            float notGroundedControl;
        };
        class character_controller_t
        {
        public:
            void* klass;
            void* monitor;
            intptr_t Object_m_CachedPtr;
            void* CharacterState_characterActor;
            void* CharacterState_characterBrain;
            void* CharacterState_characterStateController;
            planar_movement_parameters_t* planarMovementParameters;
            void* verticalMovementParameters;
            void* shrinkParameters;
            void* rigidbodyResponseParameters;
            void* OnJumpPerformed;
            void* OnGroundedJumpPerformed;
            void* OnNotGroundedJumpPerformed;
            vector3_t planarVelocity;
            vector3_t verticalVelocity;
            vector3_t externalVelocity;
            int32_t notGroundedJumpsLeft;
            float jumpTimer;
            bool isJumping;
            vector3_t jumpVelocity;
            float targetHeight;
            bool wantToShrink;
        };
        class character_state_controller_t 
        {
        public:
            void* klass;
            void* monitor;
            intptr_t Object_m_CachedPtr;
            void* characterActor;
            void* currentState;
            void* environmentParameters;
            void* movementReferenceParameters;
            void* characterBrain;
            void* states;
            void* previousState;
            void* OnStateChange;
            void* OnVolumeEnter;
            void* OnVolumeExit;
            void* OnSurfaceEnter;
            void* OnSurfaceExit;
            orthonormal_reference_t movementReference;
            vector3_t inputMovementReference;
            void* currentVolume;
            surface_t* currentSurface;
        };
        class server_manager_t 
        {
        public:
            server_manager_t* klass;
            void* monitor;
            intptr_t Object_m_CachedPtr;
            void* gameSettings;
            void* brain;
            void* playerCharacter;
            void* playerCharacterGraphics;
            void* playerAnimator;
            void* rabbitRenderer;
            void* materials;
            void* trail;
            void* teleporters;
            void* locked_teleporters;
            void* npcPrefab;
            void* racemanager;
            void* t_server;
            void* t_server_text;
            void* t_fps;
            void* t_fps_text;
            void* gameOver;
            void* emojibar;
            bool emojibar_active;
            void* flagScreen;
            void* flag_text;
            float flag_duration;
            void* discoverScreen;
            void* discover_text;
            bool uglyCode;
            void* black_screen;
            bool black_screen_active;
            uint8_t version;
            void* t_error;
            void* t_error_text;
            bool loggedIn;
            bool play_death_animation;
            bool disable_gameover;
            void* players;
            float heartbeat_roundtrip;
            bool onlinePlay;
            float rate_limit;
            void* instantiateQueue;
            void* eventQueue;
            void* client;
            void* anyIP;
            void* host;
            int32_t port;
            void* threadRecv;
            bool recvLoop;
            void* username;
            uint32_t uid;
            uint16_t unlocks;
            bool got_new_unlock;
            void* usersecret;
            float time;
            float server_time;
            int64_t start_server_time;
            float lastUpdate;
            float lastServerPacket;
            float loginAttempt;
            float lastHeartbeat;
            uint8_t trigger;
            int16_t groundedblend;
            int16_t notgroundedblend;
            float teleport_player_x;
            float teleport_player_y;
            float teleport_player_z;
            uint8_t teleport_instant;
            bool teleport_ready;
            bool blocking_position_updates;
            bool enable_movement;
            bool disable_movement;
            void* rand;
            bool otherPlayers;
            vector3_t position;
            vector3_t eulerAngles;
            vector3_t current_position;
            vector3_t current_eulerAngles;
            void* unlockAnimation;
            void* emojiAnimation;
            void* emojiUI;
            uint16_t emoji;
            uint32_t new_emoji;
            uint32_t last_emoji;
            float teleport_x;
            float teleport_y;
            float teleport_z;
            color_t fps_color;
            float noPlayerMultiplier;
            bool movementEnabled;
        };
        class udp_client_t
        {
        public:
            udp_client_t* klass;
            void* monitor;
            void* m_ClientSocket;
            bool m_Active;
            byte_array_t* m_Buffer;
            int32_t m_Family;
            bool m_CleanedUp;
            bool m_IsBroadcast;
        };
        class npc_controller_t 
        {
        public:
            npc_controller_t* klass;
            void* monitor;
            intptr_t Object_m_CachedPtr;
            vector3_t current_position;
            vector3_t next_position;
            void* rabbitRenderer;
            void* hoverName;
            void* hoverCanvas;
            hooks::types::server_manager_t* serverManager;
            string_t* npc_name;
            uint16_t unlocks;
            bool new_info;
            uint32_t uid;
            void* materials;
            float current_groundblend;
            float next_groundblend;
            float lastUpdatedTime;
            float current_notgroundblend;
            float next_notgroundblend;
            bool disable_position_updates;
            vector3_t current_rotation;
            vector3_t next_rotation;
            quaternion_t current_quaternion;
            quaternion_t next_quaternion;
            void* animation;
            void* trail;
            void* emojiAnimation;
            uint32_t last_emoji;
            float transitionSpeed;
            float animationSpeed;
            float transition;
            float animationTransition;
            bool candestroy;
            void* animator;
            bool destroyStarted;
        };

        using debug_log_t = void(__stdcall*)(void* message);
        using send_emoji_t = void(__stdcall*)(hooks::types::server_manager_t* server_manager, uint16_t emoji);
        using update_server_position_t = void(__stdcall*)(hooks::types::server_manager_t* server_manager, bool force);
        using process_jump_t = void(__stdcall*)(hooks::types::character_controller_t* instance, float dt);
        using get_character_state_t = hooks::types::character_controller_t*(__stdcall*)(hooks::types::character_state_controller_t* instance);
        using send_t = int32_t(__stdcall*)(hooks::types::udp_client_t* instance, hooks::types::byte_array_t* bytes, int32_t size);
        using send_data_t = bool(__stdcall*)(hooks::types::server_manager_t* server_manager, hooks::types::byte_array_t* packet);
        using set_position_t = void(__stdcall*)(hooks::types::npc_controller_t* npc, hooks::types::vector3_t* position);
        using set_emitting_t = void(__stdcall*)(void* instance, bool value);
        using update_t = void(__stdcall*)(hooks::types::server_manager_t* server_manager);
        using new_position_t = void(__stdcall*)(hooks::types::npc_controller_t* npc, hooks::types::vector3_t* position, hooks::types::vector3_t* rotation);
        using send_heartbeat_t = void(__stdcall*)(hooks::types::server_manager_t* server_manager);
};

    class unity_engine
    {
    public:
        static inline hooks::types::debug_log_t original_debug_log = nullptr;
        static void __stdcall debug_log_hook(
            hooks::types::message_t* message)
        {
            auto buffer = std::wstring(message->message);
            auto buffer_str = std::string(buffer.begin(), buffer.end());
            std::stringstream data(buffer_str);
            std::string line;
            while (std::getline(data, line, '\n'))
            {
                std::cout << "[LOG] " << line << std::endl;
            }
            hooks::unity_engine::original_debug_log(message);
        }
    };

    class server_manager
    {
    public:
        static inline hooks::types::send_emoji_t original_send_emoji = nullptr;
        static void __stdcall send_emoji_hook(
            hooks::types::server_manager_t* server_manager,
            uint16_t emoji)
        {
            // CSCG{Your_hack_got_reported_to_authorities!}
            // hooks::server_manager::original_send_emoji(server_manager, 13); 
            std::cout << "[EMOJI] Sending Emoji " << emoji << std::endl;
            hooks::server_manager::original_send_emoji(server_manager, emoji);
        }

        static inline hooks::types::update_server_position_t original_update_server_position = nullptr;
        static void __stdcall update_server_position_hook(
            hooks::types::server_manager_t* server_manager,
            bool force)
        {
            /*
            std::cout 
                << "[POSITION] "
                << server_manager->position.x << " | " 
                << server_manager->position.y << " | "
                << server_manager->position.z << std::endl;
            */
            //server_manager->current_position.y += 2.0;
            //force = true;
            hooks::server_manager::original_update_server_position(server_manager, force);
        }

        static inline hooks::types::send_data_t original_send_data = nullptr;
        static bool __stdcall send_data_hook(
            hooks::types::server_manager_t* server_manager,
            hooks::types::byte_array_t* packet)
        {
            if (packet->m_Items[0] == '<' && packet->m_Items[1] == '3')
            {
                // heartbeat packet
                auto heartbeat = reinterpret_cast<
                    detail::heartbeat_t*>(packet->m_Items);
                /*std::cout
                    << "[UDP] Sent Heartbeat: "
                    << std::fixed << std::setprecision(2)
                    << heartbeat->time / 10000.0
                    << std::endl;*/
            }
            else if (packet->m_Items[0] == 'P')
            {
                /*if (detail::is_running) return true;
                detail::is_running = true;*/
                // position packet
                auto position = reinterpret_cast<
                    detail::position_t*>(packet->m_Items);
                /*std::cout
                    << "{"
                    << std::fixed << std::setprecision(2)
                    << position->pos_x / 10000.0
                    << ", "
                    << position->pos_y / 10000.0
                    << ", "
                    << position->pos_z / 10000.0
                    << "},"
                    << std::endl;*/

                // CSCG{N3VER_TRUST_T1111ME}
                /*for (int i = 0; i < detail::maze_runner_positions.size(); ++i)
                {
                    position->pos_x = std::get<0>(detail::maze_runner_positions[i]) * 10000.0;
                    //position->pos_y = std::get<1>(maze_runner_positions[i]) * 10000.0;
                    position->pos_z = std::get<2>(detail::maze_runner_positions[i]) * 10000.0;
                    position->time += 0.25 * 10000.0;
                    hooks::server_manager::original_send_data(server_manager, packet);
                    // put shitty for loop here around 16k should be good !
                    for (int j = 0; j < 17000; j++) {}
                    if ((i + 1) % 4 == 0)
                    {
                        auto server_time = server_manager->server_time;
                        hooks::server_manager::original_send_heartbeat(server_manager);
                        while (server_manager->server_time == server_time);
                    }
                }

                detail::is_running = false;
                return true;*/
            }
            else if (packet->m_Items[0] == 'E')
            {
                // emoji packet
                auto emoji = reinterpret_cast<
                    detail::emoji_t*>(packet->m_Items);
                std::cout
                    << "[UDP] Sent Emoji: "
                    << emoji->emoji_id << std::endl;
            }
            else if (packet->m_Items[0] == 'L')
            {
                // login packet
                auto login = reinterpret_cast<
                    detail::login_t*>(packet->m_Items);
                std::cout
                    << "[UDP] Sent Login: "
                    << login->username << std::endl;
            }
            else
            {
                std::cout << "[UDP] Unknown packet: ";
                for (auto i = 0; i < packet->max_length; ++i)
                {
                    std::cout
                        << std::setfill('0') << std::setw(2) << std::hex
                        << static_cast<unsigned int>(packet->m_Items[i]);
                }
                std::cout << std::endl;
            }
            return hooks::server_manager::original_send_data(server_manager, packet);
        }

        static inline hooks::types::update_t original_update = nullptr;
        static void __stdcall update_hook(
            hooks::types::server_manager_t* server_manager)
        {
            hooks::server_manager::original_update(server_manager);
        }

        static inline hooks::types::send_heartbeat_t original_send_heartbeat = nullptr;
        static void __stdcall send_heartbeat_hook(
            hooks::types::server_manager_t* server_manager)
        {
            hooks::server_manager::original_send_heartbeat(server_manager);
        }
    };

    class character_controller
    {
    public:
        static inline hooks::types::process_jump_t original_process_jump = nullptr;
        static void __stdcall process_jump_hook(
            hooks::types::character_controller_t* instance, 
            float dt)
        {
            // CSCG{FLYHAX_TOO_CLOSE_TO_THE_SUN!}
            // CSCG{SOLVED_THE_MAZE...LONG_WAY_BACK!}
            dt = 0.0; // unlimited jump
            instance->jumpVelocity.y *= 1.1; // faster jump
            instance->notGroundedJumpsLeft = 100000; // air jumps
            // CSCG{SPEEDH4X_MAZE_RUNNER_BUNNYYYY}
            instance->planarMovementParameters->speed = 10.00; // original = 2
            instance->planarMovementParameters->boostMultiplier = 6.0; // shift run!
            hooks::character_controller::original_process_jump(instance, dt);
        }


        // doesnt work for some reason
        static inline hooks::types::get_character_state_t original_get_character_state = nullptr;
        static hooks::types::character_controller_t* __stdcall get_character_state(
            hooks::types::character_state_controller_t* instance)
        {
            std::cout << instance->currentSurface->speedMultiplier << std::endl;
            return hooks::character_controller::original_get_character_state(instance);  
        }
    };

    class udp_client
    {
    public:
        static inline hooks::types::send_t original_send = nullptr;
        static int32_t __stdcall send_hook(
            hooks::types::udp_client_t* instance,
            hooks::types::byte_array_t* bytes,
            int32_t size)
        {
            // 

            /*for (auto i = 0; i < size; ++i)
            {
                std::cout
                    << std::hex
                    << static_cast<unsigned int>(bytes->m_Items[i])
                    << " ";
            }
            std::cout << std::endl;*/
            return hooks::udp_client::original_send(instance, bytes, size);
        }
    };

    class npc_controller
    {
    public:
        static inline hooks::types::set_position_t original_set_position = nullptr;
        static void __stdcall set_position_hook(
            hooks::types::npc_controller_t* npc,
            hooks::types::vector3_t* position)
        {
            // doesnt work
            std::wcout
                << "[NPC] New position for " 
                << npc->npc_name->m_firstChar
                << ": "
                << position->x
                << " | "
                << position->y
                << " | "
                << position->z
                << std::endl;
            hooks::npc_controller::original_set_position(npc, position);
        }
        
        static inline hooks::types::new_position_t original_new_position = nullptr;
        static void __stdcall new_position_hook(
            hooks::types::npc_controller_t* npc,
            hooks::types::vector3_t* position,
            hooks::types::vector3_t* rotation)
        {
            /*std::wcout
                    << "[NPC] Player " << npc->npc_name->m_firstChar << ": "
                    << position->x << ","
                    << position->y << ","
                    << position->z
                    << std::endl;*/
            /*if (lstrcmpW(npc->npc_name->m_firstChar, L"The White Rabbit") == 0)
            {
                // CSCG{RADAR_HACK_XYZ}
                std::stringstream stream;
                stream << position->x << ",";
                stream << position->y << ",";
                stream << position->z;
                ipc::send(stream.str());
            }*/
            hooks::npc_controller::original_new_position(npc, position, rotation);
        }
    };

    class trail_renderer
    {
    public:
        static inline hooks::types::set_emitting_t original_set_emitting = nullptr;
        static void __stdcall set_emitting_hook(
            void* instance,
            bool value)
        {
            /*
            // v115 = unlocks
            if ( _bittest((const __int16 *)&v115, 0xCu) )
              {
                v132 = v1->trail;
                if ( !v132 )
                  goto LABEL_445;
                UnityEngine_TrailRenderer__set_emitting(v132, 1);
              }
            */
            std::cout << "[TRAIL] Emitting Trail: " << value << std::endl;
            hooks::trail_renderer::original_set_emitting(instance, value);
        }
    };
};