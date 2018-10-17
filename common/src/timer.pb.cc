// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: timer.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "timer.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace com {
namespace luyun {
namespace timer {
namespace shared {

namespace {

const ::google::protobuf::Descriptor* LYTimerMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LYTimerMsg_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* LYTimerAction_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_timer_2eproto() {
  protobuf_AddDesc_timer_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "timer.proto");
  GOOGLE_CHECK(file != NULL);
  LYTimerMsg_descriptor_ = file->message_type(0);
  static const int LYTimerMsg_offsets_[14] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, client_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, action_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, server_timer_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, client_timer_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, second_client_timer_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, after_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, repeat_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, will_stop_at_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, client_reserved1_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, client_reserved2_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, client_reserved3_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, client_reserved4_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, client_reserved5_),
  };
  LYTimerMsg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LYTimerMsg_descriptor_,
      LYTimerMsg::default_instance_,
      LYTimerMsg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LYTimerMsg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LYTimerMsg));
  LYTimerAction_descriptor_ = file->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_timer_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LYTimerMsg_descriptor_, &LYTimerMsg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_timer_2eproto() {
  delete LYTimerMsg::default_instance_;
  delete LYTimerMsg_reflection_;
}

void protobuf_AddDesc_timer_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013timer.proto\022\026com.luyun.timer.shared\"\360\002"
    "\n\nLYTimerMsg\022\017\n\007version\030\001 \002(\005\022\021\n\tclient_"
    "id\030\002 \001(\014\0225\n\006action\030\003 \002(\0162%.com.luyun.tim"
    "er.shared.LYTimerAction\022\027\n\017server_timer_"
    "id\030\004 \001(\t\022\027\n\017client_timer_id\030\005 \001(\t\022\036\n\026sec"
    "ond_client_timer_id\030\006 \001(\t\022\r\n\005after\030\007 \001(\002"
    "\022\016\n\006repeat\030\010 \001(\002\022\024\n\014will_stop_at\030\t \001(\005\022\030"
    "\n\020client_reserved1\030\013 \001(\005\022\030\n\020client_reser"
    "ved2\030\014 \001(\005\022\030\n\020client_reserved3\030\r \001(\005\022\030\n\020"
    "client_reserved4\030\016 \001(\005\022\030\n\020client_reserve"
    "d5\030\017 \001(\005*\206\001\n\rLYTimerAction\022\020\n\014LY_TIMER_R"
    "EG\020\001\022\020\n\014LY_TIMER_CAN\020\002\022\021\n\rLY_TIMER_FIRE\020"
    "\003\022\022\n\016LY_TIMER_RESET\020\004\022\021\n\rLY_TIMER_CONF\020\005"
    "\022\027\n\023LY_TIMER_SHAKE_HAND\020cB%\n\026com.luyun.t"
    "imer.sharedB\013TimerProtos", 584);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "timer.proto", &protobuf_RegisterTypes);
  LYTimerMsg::default_instance_ = new LYTimerMsg();
  LYTimerMsg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_timer_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_timer_2eproto {
  StaticDescriptorInitializer_timer_2eproto() {
    protobuf_AddDesc_timer_2eproto();
  }
} static_descriptor_initializer_timer_2eproto_;
const ::google::protobuf::EnumDescriptor* LYTimerAction_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LYTimerAction_descriptor_;
}
bool LYTimerAction_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 99:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int LYTimerMsg::kVersionFieldNumber;
const int LYTimerMsg::kClientIdFieldNumber;
const int LYTimerMsg::kActionFieldNumber;
const int LYTimerMsg::kServerTimerIdFieldNumber;
const int LYTimerMsg::kClientTimerIdFieldNumber;
const int LYTimerMsg::kSecondClientTimerIdFieldNumber;
const int LYTimerMsg::kAfterFieldNumber;
const int LYTimerMsg::kRepeatFieldNumber;
const int LYTimerMsg::kWillStopAtFieldNumber;
const int LYTimerMsg::kClientReserved1FieldNumber;
const int LYTimerMsg::kClientReserved2FieldNumber;
const int LYTimerMsg::kClientReserved3FieldNumber;
const int LYTimerMsg::kClientReserved4FieldNumber;
const int LYTimerMsg::kClientReserved5FieldNumber;
#endif  // !_MSC_VER

LYTimerMsg::LYTimerMsg()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void LYTimerMsg::InitAsDefaultInstance() {
}

LYTimerMsg::LYTimerMsg(const LYTimerMsg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void LYTimerMsg::SharedCtor() {
  _cached_size_ = 0;
  version_ = 0;
  client_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  action_ = 1;
  server_timer_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  client_timer_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  second_client_timer_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  after_ = 0;
  repeat_ = 0;
  will_stop_at_ = 0;
  client_reserved1_ = 0;
  client_reserved2_ = 0;
  client_reserved3_ = 0;
  client_reserved4_ = 0;
  client_reserved5_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LYTimerMsg::~LYTimerMsg() {
  SharedDtor();
}

void LYTimerMsg::SharedDtor() {
  if (client_id_ != &::google::protobuf::internal::kEmptyString) {
    delete client_id_;
  }
  if (server_timer_id_ != &::google::protobuf::internal::kEmptyString) {
    delete server_timer_id_;
  }
  if (client_timer_id_ != &::google::protobuf::internal::kEmptyString) {
    delete client_timer_id_;
  }
  if (second_client_timer_id_ != &::google::protobuf::internal::kEmptyString) {
    delete second_client_timer_id_;
  }
  if (this != default_instance_) {
  }
}

void LYTimerMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LYTimerMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LYTimerMsg_descriptor_;
}

const LYTimerMsg& LYTimerMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_timer_2eproto();
  return *default_instance_;
}

LYTimerMsg* LYTimerMsg::default_instance_ = NULL;

LYTimerMsg* LYTimerMsg::New() const {
  return new LYTimerMsg;
}

void LYTimerMsg::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    version_ = 0;
    if (has_client_id()) {
      if (client_id_ != &::google::protobuf::internal::kEmptyString) {
        client_id_->clear();
      }
    }
    action_ = 1;
    if (has_server_timer_id()) {
      if (server_timer_id_ != &::google::protobuf::internal::kEmptyString) {
        server_timer_id_->clear();
      }
    }
    if (has_client_timer_id()) {
      if (client_timer_id_ != &::google::protobuf::internal::kEmptyString) {
        client_timer_id_->clear();
      }
    }
    if (has_second_client_timer_id()) {
      if (second_client_timer_id_ != &::google::protobuf::internal::kEmptyString) {
        second_client_timer_id_->clear();
      }
    }
    after_ = 0;
    repeat_ = 0;
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    will_stop_at_ = 0;
    client_reserved1_ = 0;
    client_reserved2_ = 0;
    client_reserved3_ = 0;
    client_reserved4_ = 0;
    client_reserved5_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LYTimerMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 version = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &version_)));
          set_has_version();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_client_id;
        break;
      }

      // optional bytes client_id = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_client_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_client_id()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_action;
        break;
      }

      // required .com.luyun.timer.shared.LYTimerAction action = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_action:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::com::luyun::timer::shared::LYTimerAction_IsValid(value)) {
            set_action(static_cast< ::com::luyun::timer::shared::LYTimerAction >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_server_timer_id;
        break;
      }

      // optional string server_timer_id = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_server_timer_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_server_timer_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->server_timer_id().data(), this->server_timer_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_client_timer_id;
        break;
      }

      // optional string client_timer_id = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_client_timer_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_client_timer_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->client_timer_id().data(), this->client_timer_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_second_client_timer_id;
        break;
      }

      // optional string second_client_timer_id = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_second_client_timer_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_second_client_timer_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->second_client_timer_id().data(), this->second_client_timer_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(61)) goto parse_after;
        break;
      }

      // optional float after = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_after:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &after_)));
          set_has_after();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(69)) goto parse_repeat;
        break;
      }

      // optional float repeat = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_repeat:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &repeat_)));
          set_has_repeat();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_will_stop_at;
        break;
      }

      // optional int32 will_stop_at = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_will_stop_at:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &will_stop_at_)));
          set_has_will_stop_at();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_client_reserved1;
        break;
      }

      // optional int32 client_reserved1 = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_client_reserved1:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &client_reserved1_)));
          set_has_client_reserved1();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_client_reserved2;
        break;
      }

      // optional int32 client_reserved2 = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_client_reserved2:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &client_reserved2_)));
          set_has_client_reserved2();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(104)) goto parse_client_reserved3;
        break;
      }

      // optional int32 client_reserved3 = 13;
      case 13: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_client_reserved3:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &client_reserved3_)));
          set_has_client_reserved3();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(112)) goto parse_client_reserved4;
        break;
      }

      // optional int32 client_reserved4 = 14;
      case 14: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_client_reserved4:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &client_reserved4_)));
          set_has_client_reserved4();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(120)) goto parse_client_reserved5;
        break;
      }

      // optional int32 client_reserved5 = 15;
      case 15: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_client_reserved5:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &client_reserved5_)));
          set_has_client_reserved5();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void LYTimerMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 version = 1;
  if (has_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->version(), output);
  }

  // optional bytes client_id = 2;
  if (has_client_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      2, this->client_id(), output);
  }

  // required .com.luyun.timer.shared.LYTimerAction action = 3;
  if (has_action()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->action(), output);
  }

  // optional string server_timer_id = 4;
  if (has_server_timer_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->server_timer_id().data(), this->server_timer_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->server_timer_id(), output);
  }

  // optional string client_timer_id = 5;
  if (has_client_timer_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->client_timer_id().data(), this->client_timer_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      5, this->client_timer_id(), output);
  }

  // optional string second_client_timer_id = 6;
  if (has_second_client_timer_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->second_client_timer_id().data(), this->second_client_timer_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      6, this->second_client_timer_id(), output);
  }

  // optional float after = 7;
  if (has_after()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(7, this->after(), output);
  }

  // optional float repeat = 8;
  if (has_repeat()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(8, this->repeat(), output);
  }

  // optional int32 will_stop_at = 9;
  if (has_will_stop_at()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(9, this->will_stop_at(), output);
  }

  // optional int32 client_reserved1 = 11;
  if (has_client_reserved1()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(11, this->client_reserved1(), output);
  }

  // optional int32 client_reserved2 = 12;
  if (has_client_reserved2()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(12, this->client_reserved2(), output);
  }

  // optional int32 client_reserved3 = 13;
  if (has_client_reserved3()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(13, this->client_reserved3(), output);
  }

  // optional int32 client_reserved4 = 14;
  if (has_client_reserved4()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(14, this->client_reserved4(), output);
  }

  // optional int32 client_reserved5 = 15;
  if (has_client_reserved5()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(15, this->client_reserved5(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* LYTimerMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 version = 1;
  if (has_version()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->version(), target);
  }

  // optional bytes client_id = 2;
  if (has_client_id()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->client_id(), target);
  }

  // required .com.luyun.timer.shared.LYTimerAction action = 3;
  if (has_action()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->action(), target);
  }

  // optional string server_timer_id = 4;
  if (has_server_timer_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->server_timer_id().data(), this->server_timer_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->server_timer_id(), target);
  }

  // optional string client_timer_id = 5;
  if (has_client_timer_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->client_timer_id().data(), this->client_timer_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->client_timer_id(), target);
  }

  // optional string second_client_timer_id = 6;
  if (has_second_client_timer_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->second_client_timer_id().data(), this->second_client_timer_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->second_client_timer_id(), target);
  }

  // optional float after = 7;
  if (has_after()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(7, this->after(), target);
  }

  // optional float repeat = 8;
  if (has_repeat()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(8, this->repeat(), target);
  }

  // optional int32 will_stop_at = 9;
  if (has_will_stop_at()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, this->will_stop_at(), target);
  }

  // optional int32 client_reserved1 = 11;
  if (has_client_reserved1()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, this->client_reserved1(), target);
  }

  // optional int32 client_reserved2 = 12;
  if (has_client_reserved2()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, this->client_reserved2(), target);
  }

  // optional int32 client_reserved3 = 13;
  if (has_client_reserved3()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(13, this->client_reserved3(), target);
  }

  // optional int32 client_reserved4 = 14;
  if (has_client_reserved4()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(14, this->client_reserved4(), target);
  }

  // optional int32 client_reserved5 = 15;
  if (has_client_reserved5()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(15, this->client_reserved5(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int LYTimerMsg::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 version = 1;
    if (has_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->version());
    }

    // optional bytes client_id = 2;
    if (has_client_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->client_id());
    }

    // required .com.luyun.timer.shared.LYTimerAction action = 3;
    if (has_action()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->action());
    }

    // optional string server_timer_id = 4;
    if (has_server_timer_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->server_timer_id());
    }

    // optional string client_timer_id = 5;
    if (has_client_timer_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->client_timer_id());
    }

    // optional string second_client_timer_id = 6;
    if (has_second_client_timer_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->second_client_timer_id());
    }

    // optional float after = 7;
    if (has_after()) {
      total_size += 1 + 4;
    }

    // optional float repeat = 8;
    if (has_repeat()) {
      total_size += 1 + 4;
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional int32 will_stop_at = 9;
    if (has_will_stop_at()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->will_stop_at());
    }

    // optional int32 client_reserved1 = 11;
    if (has_client_reserved1()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->client_reserved1());
    }

    // optional int32 client_reserved2 = 12;
    if (has_client_reserved2()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->client_reserved2());
    }

    // optional int32 client_reserved3 = 13;
    if (has_client_reserved3()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->client_reserved3());
    }

    // optional int32 client_reserved4 = 14;
    if (has_client_reserved4()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->client_reserved4());
    }

    // optional int32 client_reserved5 = 15;
    if (has_client_reserved5()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->client_reserved5());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LYTimerMsg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LYTimerMsg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LYTimerMsg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LYTimerMsg::MergeFrom(const LYTimerMsg& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_version()) {
      set_version(from.version());
    }
    if (from.has_client_id()) {
      set_client_id(from.client_id());
    }
    if (from.has_action()) {
      set_action(from.action());
    }
    if (from.has_server_timer_id()) {
      set_server_timer_id(from.server_timer_id());
    }
    if (from.has_client_timer_id()) {
      set_client_timer_id(from.client_timer_id());
    }
    if (from.has_second_client_timer_id()) {
      set_second_client_timer_id(from.second_client_timer_id());
    }
    if (from.has_after()) {
      set_after(from.after());
    }
    if (from.has_repeat()) {
      set_repeat(from.repeat());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_will_stop_at()) {
      set_will_stop_at(from.will_stop_at());
    }
    if (from.has_client_reserved1()) {
      set_client_reserved1(from.client_reserved1());
    }
    if (from.has_client_reserved2()) {
      set_client_reserved2(from.client_reserved2());
    }
    if (from.has_client_reserved3()) {
      set_client_reserved3(from.client_reserved3());
    }
    if (from.has_client_reserved4()) {
      set_client_reserved4(from.client_reserved4());
    }
    if (from.has_client_reserved5()) {
      set_client_reserved5(from.client_reserved5());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LYTimerMsg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LYTimerMsg::CopyFrom(const LYTimerMsg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LYTimerMsg::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000005) != 0x00000005) return false;

  return true;
}

void LYTimerMsg::Swap(LYTimerMsg* other) {
  if (other != this) {
    std::swap(version_, other->version_);
    std::swap(client_id_, other->client_id_);
    std::swap(action_, other->action_);
    std::swap(server_timer_id_, other->server_timer_id_);
    std::swap(client_timer_id_, other->client_timer_id_);
    std::swap(second_client_timer_id_, other->second_client_timer_id_);
    std::swap(after_, other->after_);
    std::swap(repeat_, other->repeat_);
    std::swap(will_stop_at_, other->will_stop_at_);
    std::swap(client_reserved1_, other->client_reserved1_);
    std::swap(client_reserved2_, other->client_reserved2_);
    std::swap(client_reserved3_, other->client_reserved3_);
    std::swap(client_reserved4_, other->client_reserved4_);
    std::swap(client_reserved5_, other->client_reserved5_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LYTimerMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LYTimerMsg_descriptor_;
  metadata.reflection = LYTimerMsg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace shared
}  // namespace timer
}  // namespace luyun
}  // namespace com

// @@protoc_insertion_point(global_scope)
