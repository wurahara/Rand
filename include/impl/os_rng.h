#ifndef RAND_OS_H
#define RAND_OS_H

#include "core/rng.h"

namespace rng::impl {

class OsRng : public core::RngCore {
public:
    uint32_t get_uint32() override;
    uint64_t get_uint64() override;
    void fill_bytes(const std::span<uint8_t> &dest) noexcept override;
};

} // namespace rng::impl

#endif //RAND_OS_H