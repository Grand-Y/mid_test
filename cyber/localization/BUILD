load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "libcyber_test_localization.so",
    linkshared = True,
    linkstatic = True,
    deps = [":cyber_test_localization_lib"],
)

cc_library(
    name = "cyber_test_localization_lib",
    srcs = ["n2.cc"],
    hdrs = ["n2.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
    ],
)


filegroup(
    name = "conf",
    srcs = [
        "//cyber/a_mid_test/cyber:cyber_test.dag",
        # ":common-next.dag",
        "//cyber/a_mid_test/cyber:cyber_test.launch",
    ],
)

install(
    name = "install",
    data = [
        ":conf",
    ],
    # We want to install channel_*_writer into runtime_dest
    # rather than bin/
    runtime_dest = "cyber/a_mid_test/cyber/localization",
    targets = [
        ":libcyber_test_localization.so",
        # ":libcommon_next_component_example.so",
    ],
)

cpplint()
