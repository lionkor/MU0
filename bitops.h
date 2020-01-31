#ifndef BITOPS_H
#define BITOPS_H

/// Flips the bit at position n
template<typename _IntT, typename _SmallIntT>
inline _IntT& bit_flip(_IntT& i, _SmallIntT n) {
    return i ^= 1 << (n - 1);
}

/// Sets the bit at position n
template<typename _IntT, typename _SmallIntT>
inline _IntT& bit_set(_IntT& i, _SmallIntT n) {
    return i |= 1 << (n - 1);
}

/// Sets all bits in the mask in i
template<typename _IntT>
inline _IntT& bit_set_mask(_IntT& i, _IntT mask) {
    return i |= mask;
}

/// Unsets the bit at position n
template<typename _IntT, typename _SmallIntT>
inline _IntT& bit_unset(_IntT& i, _SmallIntT n) {
    return i &= ~(1 << (n - 1));
}

/// Checks whether the bit at position n is set
template<typename _IntT, typename _SmallIntT>
inline constexpr bool is_bit_set(_IntT i, _SmallIntT n) {
    return i & (1 << (n - 1));
}

/// Checks whether all bits in the mask are set in i
template<typename _IntT>
inline constexpr bool is_bitmask_set(_IntT i, _IntT mask) {
    return (i & mask) == mask;
}

#endif // BITOPS_H
