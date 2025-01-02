load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])


cc_binary(
    name = "libbase_test_1_1.so",
    linkshared = True,
    linkstatic = True,
    deps = [":pub_lib", ":sub_lib"],
)

cc_library(
    name = "pub_lib",
    srcs = ["PubComponent.cc"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/a_mid_test/cyber:amt_msg_cc_proto",
    ],
)

cc_library(
    name = "sub_lib",
    srcs = ["SubComponent.cc"],
    hdrs = ["SubComponent.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/a_mid_test/cyber:amt_msg_cc_proto",
    ],
)

install(
    name = "install",
    data = [
        # ":conf",
    ],
    # We want to install channel_*_writer into runtime_dest
    # rather than bin/
    runtime_dest = "cyber/a_mid_test/cyber/base_test/b1_1",
    targets = [
        ":libbase_test_1_1.so",
        # ":libcommon_next_component_example.so",
    ],
)

cpplint()