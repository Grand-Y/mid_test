load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//tools/install:install.bzl", "install")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])


cc_proto_library(
    name = "amt_msg_cc_proto",
    deps = [":amt_msg_proto",],
)

proto_library(
    name = "amt_msg_proto",
    srcs = ["amt_msg.proto"],
)

filegroup(
    name = "conf",
    srcs = [
        "cyber_test.dag",
        "cyber_test.launch",
    ],
)
