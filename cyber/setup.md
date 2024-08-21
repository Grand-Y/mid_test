## 编译单独的test_model.cpp、test_onnx.cpp
注意：apollo的容器中自带libtorch_cpu和libtorch_gpu，无需再去pytorch官网下载。官网下载的新版libtorch需要高版本gcc，容器中的gcc-7.5.0会编译失败。
其中：
-I：指定编译器的头文件搜索路径
-L：指定编译器的库文件搜索路径
-l：指定要链接的库名
-Wl,-rpath=xxx：将库路径嵌入到可执行文件中，防止编译通过但运行时找不到库文件
```shell
g++ -o test_libtorch test_libtorch.cpp \
-I/usr/local/include/opencv4 \
-I/usr/local/libtorch_cpu/include \
-I/usr/local/libtorch_cpu/include/torch/csrc/api/include \
-L/usr/local/libtorch_cpu/lib \
-ltorch_cpu -ltorch -lc10 \
-lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_dnn \
-Wl,-rpath,/usr/local/libtorch_cpu/lib
```
```shell
g++ -o test_onnx test_onnx.cpp \
-I/usr/local/include/opencv4 \
-I/apollo/cyber/a_mid_test/third_party \
-L/apollo/cyber/a_mid_test/third_party/onnxruntime/lib \
-lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui \
-lonnxruntime -Wl,-rpath=/apollo/cyber/a_mid_test/3rd_algs/onnxruntime/lib
```
```shell
g++ -o test_onnx test_onnx.cpp \
-I/usr/local/include/opencv4 \
-I/usr/local/include \
-L/usr/local/include/onnxruntime/lib \
-lopencv_core -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_dnn \
-lonnxruntime -Wl,-rpath=/usr/local/include/onnxruntime/lib
```