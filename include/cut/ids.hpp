#ifndef INCLUDE_CUT_IDS_H_
#define INCLUDE_CUT_IDS_H_

#include <functional>

namespace cut {
// A generic class that can be used as a unique identifier
// Tag's are used so that different Aliased IDs cannot be compared
template<typename T, typename Tag> class ID
{
public:
  constexpr ID() : id_(0) {}
  constexpr explicit ID(const T& identifier) : id_(identifier), valid_(true) {}

  constexpr bool operator==(const ID<T, Tag>& other) const { return id_ == other.Get(); }

  const T& Get() const { return id_; }

private:
  T id_;
  bool valid_{ false };
};

// Examples of using tagged IDs
// struct ShaderIdTag
// {
// };
// using ShaderID = ID<unsigned int, ShaderIdTag>;

// struct TextureTag
// {
// };
// using TextureID = ID<unsigned int, TextureTag>;

// Examples of templated tagged IDs
// template<typename ComponentName> using ComponentID = ID<uint64_t, ComponentName>;
// template<typename SystemName> using SystemID = ID<uint64_t, SystemName>;

}// namespace cut

namespace std {
/**
 * @brief Specialisation for cut::ID so that it can be used in standard library hashing containers
 *
 * @tparam T The type for ID
 * @tparam Tag
 */

template<typename T, typename Tag> struct hash<cut::ID<T, Tag>>
{
  T operator()(const cut::ID<T, Tag>& identifier) const noexcept { return identifier.Get(); }
};
}// namespace std

#endif// INCLUDE_CUT_IDS_H_