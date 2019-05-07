#pragma once

#include <serialization/serialization.h>
#include <optional>

namespace shadowsocks
{

struct ss_config
{
    std::optional<std::string> log_level;
    std::string server_address;
    uint16_t server_port;
    std::optional<std::string> local_address;
    std::optional<uint16_t> local_port;
    std::string method;
    std::string password;
    uint32_t timeout;
    std::optional<bool> no_delay;
    std::optional<uint32_t> workers;
    
    SERIALIZATION_DEFINE(log_level, server_address, server_port, local_address, local_port, method, password, timeout, no_delay, workers)
};

}