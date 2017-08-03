// Generated by the protocol buffer compiler.  DO NOT EDIT!

#import "ProtocolBuffers/ProtocolBuffers.h"

// @@protoc_insertion_point(imports)

@class MessagePush;
@class MessagePushBuilder;



@interface MessagepushRoot : NSObject {
}
+ (PBExtensionRegistry*) extensionRegistry;
+ (void) registerAllExtensions:(PBMutableExtensionRegistry*) registry;
@end

#define MessagePush_topic @"topic"
#define MessagePush_content @"content"
#define MessagePush_from @"pb_from"
@interface MessagePush : PBGeneratedMessage<GeneratedMessageProtocol> {
@private
  BOOL hasTopic_:1;
  BOOL hasContent_:1;
  BOOL hasFrom_:1;
  NSString* topic;
  NSString* content;
  NSString* pb_from;
}
- (BOOL) hasTopic;
- (BOOL) hasContent;
- (BOOL) hasFrom;
@property (readonly, strong) NSString* topic;
@property (readonly, strong) NSString* content;
@property (readonly, strong) NSString* pb_from;

+ (instancetype) defaultInstance;
- (instancetype) defaultInstance;

- (BOOL) isInitialized;
- (void) writeToCodedOutputStream:(PBCodedOutputStream*) output;
- (MessagePushBuilder*) builder;
+ (MessagePushBuilder*) builder;
+ (MessagePushBuilder*) builderWithPrototype:(MessagePush*) prototype;
- (MessagePushBuilder*) toBuilder;

+ (MessagePush*) parseFromData:(NSData*) data;
+ (MessagePush*) parseFromData:(NSData*) data extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (MessagePush*) parseFromInputStream:(NSInputStream*) input;
+ (MessagePush*) parseFromInputStream:(NSInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
+ (MessagePush*) parseFromCodedInputStream:(PBCodedInputStream*) input;
+ (MessagePush*) parseFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;
@end

@interface MessagePushBuilder : PBGeneratedMessageBuilder {
@private
  MessagePush* resultMessagePush;
}

- (MessagePush*) defaultInstance;

- (MessagePushBuilder*) clear;
- (MessagePushBuilder*) clone;

- (MessagePush*) build;
- (MessagePush*) buildPartial;

- (MessagePushBuilder*) mergeFrom:(MessagePush*) other;
- (MessagePushBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input;
- (MessagePushBuilder*) mergeFromCodedInputStream:(PBCodedInputStream*) input extensionRegistry:(PBExtensionRegistry*) extensionRegistry;

- (BOOL) hasTopic;
- (NSString*) topic;
- (MessagePushBuilder*) setTopic:(NSString*) value;
- (MessagePushBuilder*) clearTopic;

- (BOOL) hasContent;
- (NSString*) content;
- (MessagePushBuilder*) setContent:(NSString*) value;
- (MessagePushBuilder*) clearContent;

- (BOOL) hasFrom;
- (NSString*) pb_from;
- (MessagePushBuilder*) setFrom:(NSString*) value;
- (MessagePushBuilder*) clearFrom;
@end


// @@protoc_insertion_point(global_scope)
