// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: find_one_contact_request.proto

#include "find_one_contact_request.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace find_one_contact_request {
PROTOBUF_CONSTEXPR FindOneContactRequest::FindOneContactRequest(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.uid_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct FindOneContactRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FindOneContactRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~FindOneContactRequestDefaultTypeInternal() {}
  union {
    FindOneContactRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FindOneContactRequestDefaultTypeInternal _FindOneContactRequest_default_instance_;
}  // namespace find_one_contact_request
static ::_pb::Metadata file_level_metadata_find_5fone_5fcontact_5frequest_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_find_5fone_5fcontact_5frequest_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_find_5fone_5fcontact_5frequest_2eproto = nullptr;

const uint32_t TableStruct_find_5fone_5fcontact_5frequest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::find_one_contact_request::FindOneContactRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::find_one_contact_request::FindOneContactRequest, _impl_.uid_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::find_one_contact_request::FindOneContactRequest)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::find_one_contact_request::_FindOneContactRequest_default_instance_._instance,
};

const char descriptor_table_protodef_find_5fone_5fcontact_5frequest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\036find_one_contact_request.proto\022\030find_o"
  "ne_contact_request\"$\n\025FindOneContactRequ"
  "est\022\013\n\003uid\030\001 \001(\tb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_find_5fone_5fcontact_5frequest_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_find_5fone_5fcontact_5frequest_2eproto = {
    false, false, 104, descriptor_table_protodef_find_5fone_5fcontact_5frequest_2eproto,
    "find_one_contact_request.proto",
    &descriptor_table_find_5fone_5fcontact_5frequest_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_find_5fone_5fcontact_5frequest_2eproto::offsets,
    file_level_metadata_find_5fone_5fcontact_5frequest_2eproto, file_level_enum_descriptors_find_5fone_5fcontact_5frequest_2eproto,
    file_level_service_descriptors_find_5fone_5fcontact_5frequest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_find_5fone_5fcontact_5frequest_2eproto_getter() {
  return &descriptor_table_find_5fone_5fcontact_5frequest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_find_5fone_5fcontact_5frequest_2eproto(&descriptor_table_find_5fone_5fcontact_5frequest_2eproto);
namespace find_one_contact_request {

// ===================================================================

class FindOneContactRequest::_Internal {
 public:
};

FindOneContactRequest::FindOneContactRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:find_one_contact_request.FindOneContactRequest)
}
FindOneContactRequest::FindOneContactRequest(const FindOneContactRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  FindOneContactRequest* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.uid_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.uid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.uid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_uid().empty()) {
    _this->_impl_.uid_.Set(from._internal_uid(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:find_one_contact_request.FindOneContactRequest)
}

inline void FindOneContactRequest::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.uid_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.uid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.uid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

FindOneContactRequest::~FindOneContactRequest() {
  // @@protoc_insertion_point(destructor:find_one_contact_request.FindOneContactRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void FindOneContactRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.uid_.Destroy();
}

void FindOneContactRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void FindOneContactRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:find_one_contact_request.FindOneContactRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.uid_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* FindOneContactRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string uid = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_uid();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "find_one_contact_request.FindOneContactRequest.uid"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* FindOneContactRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:find_one_contact_request.FindOneContactRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string uid = 1;
  if (!this->_internal_uid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_uid().data(), static_cast<int>(this->_internal_uid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "find_one_contact_request.FindOneContactRequest.uid");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_uid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:find_one_contact_request.FindOneContactRequest)
  return target;
}

size_t FindOneContactRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:find_one_contact_request.FindOneContactRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string uid = 1;
  if (!this->_internal_uid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_uid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData FindOneContactRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    FindOneContactRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*FindOneContactRequest::GetClassData() const { return &_class_data_; }


void FindOneContactRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<FindOneContactRequest*>(&to_msg);
  auto& from = static_cast<const FindOneContactRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:find_one_contact_request.FindOneContactRequest)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_uid().empty()) {
    _this->_internal_set_uid(from._internal_uid());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void FindOneContactRequest::CopyFrom(const FindOneContactRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:find_one_contact_request.FindOneContactRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FindOneContactRequest::IsInitialized() const {
  return true;
}

void FindOneContactRequest::InternalSwap(FindOneContactRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.uid_, lhs_arena,
      &other->_impl_.uid_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata FindOneContactRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_find_5fone_5fcontact_5frequest_2eproto_getter, &descriptor_table_find_5fone_5fcontact_5frequest_2eproto_once,
      file_level_metadata_find_5fone_5fcontact_5frequest_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace find_one_contact_request
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::find_one_contact_request::FindOneContactRequest*
Arena::CreateMaybeMessage< ::find_one_contact_request::FindOneContactRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::find_one_contact_request::FindOneContactRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
