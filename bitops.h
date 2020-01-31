#ifndef BITOPS_H
#define BITOPS_H

template<typename _IntT, typename _SmallIntT>
inline _IntT& bitflip(_IntT& i, _SmallIntT n) {
    return i ^= 1 << (n - 1);
}

template<typename _IntT, typename _SmallIntT>
inline _IntT& bitset(_IntT& i, _SmallIntT n) {
    return i |= 1 << (n - 1);
}

template<typename _IntT, typename _SmallIntT>
inline _IntT& bitunset(_IntT& i, _SmallIntT n) {
    return i &= ~(1 << (n - 1));
}

template<typename _IntT, typename _SmallIntT>
constexpr bool is_bit_set(const _IntT& i, _SmallIntT n) {
    return i & (1 << (n - 1));
}

#endif // BITOPS_H
