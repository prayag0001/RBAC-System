#include "utils.h"
#include <jwt-cpp/jwt.h>

// Generate JWT token
std::string generate_token(const std::string& u, const std::string& role) {
    auto token = jwt::create()
        .set_issuer("auth_server")
        .set_type("JWT")
        .set_payload_claim("username", jwt::claim(u))
        .set_payload_claim("role", jwt::claim(role))
        .sign(jwt::algorithm::hs256{"secret"});
    return token;
}

// Decode and verify JWT token
std::pair<std::string, std::string> decode_token(const std::string& token) {
    auto decoded = jwt::decode(token);
    auto username = decoded.get_payload_claim("username").as_string();
    auto role = decoded.get_payload_claim("role").as_string();
    return {username, role};
}
