#ifndef RAND_RNG_H
#define RAND_RNG_H

#include <cstdint>
#include <span>

namespace rng::core {

class RngCore {
public:
    virtual uint32_t get_uint32() = 0;
    virtual uint64_t get_uint64() = 0;
    virtual void fill_bytes(const std::span<uint8_t> &dest) = 0;
};

} // namespace rand::core

#endif //RAND_RNG_H