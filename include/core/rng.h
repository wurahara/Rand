#ifndef RAND_RNG_H
#define RAND_RNG_H

#include <cstdint>
#include <span>

namespace rng::core {

/**
 * @brief The <tt>RngCore</tt> class is the base class for all random number generators.
 * @details This abstract class provides the interface for all random number generators. Three different methods for
 *          generating random data are provided since the optimal implementation of each is dependent on the type
 *          of generator. There is no required relationship between the output of each.
 */
class RngCore {
public:
    /**
     * @brief Randomly generates a random 32-bit unsigned integer.
     * @return the next random 32-bit unsigned integer.
     */
    virtual uint32_t get_uint32() = 0;

    /**
     * @brief Randomly generates a random 64-bit unsigned integer.
     * @return the next random 64-bit unsigned integer.
     */
    virtual uint64_t get_uint64() = 0;

    /**
     * @brief Fills the given buffer with random bytes.
     * @param dest the destination buffer to be filled.
     * @details This method should guarantee that <tt>dest</tt> is entirely filled with new data.
     */
    virtual void fill_bytes(const std::span<uint8_t> &dest) = 0;
};

} // namespace rand::core

#endif //RAND_RNG_H