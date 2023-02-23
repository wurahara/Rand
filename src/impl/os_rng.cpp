#include "impl/os_rng.h"

#include <array>
#include <random>

#include "utils/bit.h"

namespace rng::impl {

using util::bit::from_le_bytes;

uint32_t OsRng::get_uint32() {
    std::array<uint8_t, 4> buf{};
    this->fill_bytes(buf);
    return from_le_bytes<uint32_t>(buf);
}

uint64_t OsRng::get_uint64() {
    std::array<uint8_t, 8> buf{};
    this->fill_bytes(buf);
    return from_le_bytes<uint64_t>(buf);
}

void OsRng::fill_bytes(const std::span<uint8_t> &dest) noexcept {
    std::random_device device;
    std::mt19937_64 engine{device()};
    std::uniform_int_distribution<uint8_t> distribution{
            std::numeric_limits<uint8_t>::min(),
            std::numeric_limits<uint8_t>::max()
    };
    for (uint8_t &element: dest) element = distribution(engine);
}

} // namespace rng::impl