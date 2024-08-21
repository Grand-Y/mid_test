load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//tools/install:install.bzl", "install")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "libcyber_test_perception.so",
    linkshared = True,
    linkstatic = True,
    deps = [":n1_lib", ":camera_timer_lib", ":lane_component_lib", ":yolo_component_lib", 
            ":tracker_component_lib", ":final_component_lib"],
)

cc_library(
    name = "n1_lib",
    srcs = ["n1.cc"],
    hdrs = ["n1.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
    ],
)

cc_binary(
    name = "rd_writer_camera",
    srcs = ["rd_writer_camera.cc"],
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
    ],
)

cc_binary(
    name = "rd_writer_lidar",
    srcs = ["rd_writer_lidar.cc"],
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
    ],
)

cc_binary(
    name = "rd_writer_imu",
    srcs = ["rd_writer_imu.cc"],
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
    ],
)


cc_binary(
    name = "test_opencv",
    srcs = ["test.cpp"],
    deps = [
        "//cyber",
        "//cyber/examples/proto:examples_cc_proto",
    ],
    copts = [
        "-I/usr/local/include/opencv4",
    ],
    linkopts = [
        "-L/usr/local/lib",
        "-lopencv_core",
        "-lopencv_imgproc",
        "-lopencv_highgui",
        "-lopencv_imgcodecs",
    ],
)

filegroup(
    name = "conf",
    srcs = [
        "//cyber/a_mid_test/cyber:cyber_test.dag",
        "//cyber/a_mid_test/cyber:cyber_test.launch",
    ],
)


cc_library(
    name = "camera_timer_lib",
    srcs = ["CameraTimer.cc"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/a_mid_test/cyber:amt_msg_cc_proto",
    ],
    copts = [
        "-I/usr/local/include/opencv4",
    ],
    linkopts = [
        "-L/usr/local/lib",
        "-lopencv_core",
        "-lopencv_imgproc",
        "-lopencv_highgui",
        "-lopencv_imgcodecs",
    ],
)

cc_library(
    name = "lane_component_lib",
    srcs = ["LaneComponent.cc", "lane_detect.cpp"],
    hdrs = ["LaneComponent.h", "lane_detect.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/a_mid_test/cyber:amt_msg_cc_proto",
    ],
    copts = [
        "-I/usr/local/include/opencv4",
    ],
    linkopts = [
        "-L/usr/local/lib",
        "-lopencv_core",
        "-lopencv_imgproc",
        "-lopencv_highgui",
        "-lopencv_imgcodecs",
    ],
)

cc_library(
    name = "yolo_component_lib",
    srcs = ["YoloComponent.cc", "yolo_detect.cpp"],
    hdrs = ["YoloComponent.h", "yolo_detect.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/a_mid_test/cyber:amt_msg_cc_proto",
    ],
    copts = [
        "-I/usr/local/include/opencv4",
        "-I/usr/local/include",
    ],
    linkopts = [
        "-L/usr/local/lib",
        "-L/usr/local/include/onnxruntime/lib",
        "-lopencv_core",
        "-lopencv_imgproc",
        "-lopencv_highgui",
        "-lopencv_imgcodecs",
        "-lopencv_dnn",
        "-lonnxruntime",
        "-Wl,-rpath=/usr/local/include/onnxruntime/lib"
    ],
)

cc_library(
    name = "tracker_component_lib",
    srcs = ["TrackerComponent.cc"],
    hdrs = ["TrackerComponent.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//cyber/a_mid_test/cyber:amt_msg_cc_proto",
    ],
    copts = [
        "-I/usr/local/include/opencv4",
    ],
    linkopts = [
        "-L/usr/local/lib",
        "-lopencv_core",
        "-lopencv_imgproc",
        "-lopencv_highgui",
        "-lopencv_imgcodecs",
        "-lopencv_dnn",
        "-lopencv_tracking",
        "-lopencv_video",
    ],
)

cc_library(
    name = "final_component_lib",
    srcs = ["FinalComponent.cc"],
    hdrs = ["FinalComponent.h"],
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
        ":conf",
    ],
    # We want to install channel_*_writer into runtime_dest
    # rather than bin/
    runtime_dest = "cyber/a_mid_test/cyber/perception",
    targets = [
        ":rd_writer_camera",
        ":rd_writer_lidar",
        ":rd_writer_imu",
        ":test_opencv",
        ":libcyber_test_perception.so",
        # ":libcommon_next_component_example.so",
    ],
)

cpplint()
