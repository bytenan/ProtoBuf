// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: del_contact_response.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_del_5fcontact_5fresponse_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_del_5fcontact_5fresponse_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_del_5fcontact_5fresponse_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_del_5fcontact_5fresponse_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_del_5fcontact_5fresponse_2eproto;
namespace del_contact_response {
class DelContactResponse;
struct DelContactResponseDefaultTypeInternal;
extern DelContactResponseDefaultTypeInternal _DelContactResponse_default_instance_;
}  // namespace del_contact_response
PROTOBUF_NAMESPACE_OPEN
template<> ::del_contact_response::DelContactResponse* Arena::CreateMaybeMessage<::del_contact_response::DelContactResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace del_contact_response {

// ===================================================================

class DelContactResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:del_contact_response.DelContactResponse) */ {
 public:
  inline DelContactResponse() : DelContactResponse(nullptr) {}
  ~DelContactResponse() override;
  explicit PROTOBUF_CONSTEXPR DelContactResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DelContactResponse(const DelContactResponse& from);
  DelContactResponse(DelContactResponse&& from) noexcept
    : DelContactResponse() {
    *this = ::std::move(from);
  }

  inline DelContactResponse& operator=(const DelContactResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline DelContactResponse& operator=(DelContactResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DelContactResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const DelContactResponse* internal_default_instance() {
    return reinterpret_cast<const DelContactResponse*>(
               &_DelContactResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(DelContactResponse& a, DelContactResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(DelContactResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DelContactResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  DelContactResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<DelContactResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const DelContactResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const DelContactResponse& from) {
    DelContactResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DelContactResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "del_contact_response.DelContactResponse";
  }
  protected:
  explicit DelContactResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrorDescFieldNumber = 2,
    kUidFieldNumber = 3,
    kSuccessFieldNumber = 1,
  };
  // string error_desc = 2;
  void clear_error_desc();
  const std::string& error_desc() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_error_desc(ArgT0&& arg0, ArgT... args);
  std::string* mutable_error_desc();
  PROTOBUF_NODISCARD std::string* release_error_desc();
  void set_allocated_error_desc(std::string* error_desc);
  private:
  const std::string& _internal_error_desc() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_error_desc(const std::string& value);
  std::string* _internal_mutable_error_desc();
  public:

  // string uid = 3;
  void clear_uid();
  const std::string& uid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_uid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_uid();
  PROTOBUF_NODISCARD std::string* release_uid();
  void set_allocated_uid(std::string* uid);
  private:
  const std::string& _internal_uid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_uid(const std::string& value);
  std::string* _internal_mutable_uid();
  public:

  // bool success = 1;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // @@protoc_insertion_point(class_scope:del_contact_response.DelContactResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr error_desc_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr uid_;
    bool success_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_del_5fcontact_5fresponse_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DelContactResponse

// bool success = 1;
inline void DelContactResponse::clear_success() {
  _impl_.success_ = false;
}
inline bool DelContactResponse::_internal_success() const {
  return _impl_.success_;
}
inline bool DelContactResponse::success() const {
  // @@protoc_insertion_point(field_get:del_contact_response.DelContactResponse.success)
  return _internal_success();
}
inline void DelContactResponse::_internal_set_success(bool value) {
  
  _impl_.success_ = value;
}
inline void DelContactResponse::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:del_contact_response.DelContactResponse.success)
}

// string error_desc = 2;
inline void DelContactResponse::clear_error_desc() {
  _impl_.error_desc_.ClearToEmpty();
}
inline const std::string& DelContactResponse::error_desc() const {
  // @@protoc_insertion_point(field_get:del_contact_response.DelContactResponse.error_desc)
  return _internal_error_desc();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DelContactResponse::set_error_desc(ArgT0&& arg0, ArgT... args) {
 
 _impl_.error_desc_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:del_contact_response.DelContactResponse.error_desc)
}
inline std::string* DelContactResponse::mutable_error_desc() {
  std::string* _s = _internal_mutable_error_desc();
  // @@protoc_insertion_point(field_mutable:del_contact_response.DelContactResponse.error_desc)
  return _s;
}
inline const std::string& DelContactResponse::_internal_error_desc() const {
  return _impl_.error_desc_.Get();
}
inline void DelContactResponse::_internal_set_error_desc(const std::string& value) {
  
  _impl_.error_desc_.Set(value, GetArenaForAllocation());
}
inline std::string* DelContactResponse::_internal_mutable_error_desc() {
  
  return _impl_.error_desc_.Mutable(GetArenaForAllocation());
}
inline std::string* DelContactResponse::release_error_desc() {
  // @@protoc_insertion_point(field_release:del_contact_response.DelContactResponse.error_desc)
  return _impl_.error_desc_.Release();
}
inline void DelContactResponse::set_allocated_error_desc(std::string* error_desc) {
  if (error_desc != nullptr) {
    
  } else {
    
  }
  _impl_.error_desc_.SetAllocated(error_desc, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.error_desc_.IsDefault()) {
    _impl_.error_desc_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:del_contact_response.DelContactResponse.error_desc)
}

// string uid = 3;
inline void DelContactResponse::clear_uid() {
  _impl_.uid_.ClearToEmpty();
}
inline const std::string& DelContactResponse::uid() const {
  // @@protoc_insertion_point(field_get:del_contact_response.DelContactResponse.uid)
  return _internal_uid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DelContactResponse::set_uid(ArgT0&& arg0, ArgT... args) {
 
 _impl_.uid_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:del_contact_response.DelContactResponse.uid)
}
inline std::string* DelContactResponse::mutable_uid() {
  std::string* _s = _internal_mutable_uid();
  // @@protoc_insertion_point(field_mutable:del_contact_response.DelContactResponse.uid)
  return _s;
}
inline const std::string& DelContactResponse::_internal_uid() const {
  return _impl_.uid_.Get();
}
inline void DelContactResponse::_internal_set_uid(const std::string& value) {
  
  _impl_.uid_.Set(value, GetArenaForAllocation());
}
inline std::string* DelContactResponse::_internal_mutable_uid() {
  
  return _impl_.uid_.Mutable(GetArenaForAllocation());
}
inline std::string* DelContactResponse::release_uid() {
  // @@protoc_insertion_point(field_release:del_contact_response.DelContactResponse.uid)
  return _impl_.uid_.Release();
}
inline void DelContactResponse::set_allocated_uid(std::string* uid) {
  if (uid != nullptr) {
    
  } else {
    
  }
  _impl_.uid_.SetAllocated(uid, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.uid_.IsDefault()) {
    _impl_.uid_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:del_contact_response.DelContactResponse.uid)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace del_contact_response

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_del_5fcontact_5fresponse_2eproto