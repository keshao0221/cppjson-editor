# cppjson

一个用于学习 C++ 与 JSON 原理的轻量级 JSON 解析与编辑器。

---

## 功能介绍

- **JSON 数据建模**：使用结构体与枚举完整表示 JSON 的 6 种类型（null、bool、数字、字符串、数组、对象）。
- **格式化输出**：支持树状缩进的 JSON 美观打印。
- **JSON 解析**（开发中）：将 JSON 字符串转换为核心数据结构。
- **简单接口**：逐步提供增、删、改、查和文件读写能力。

---

## 使用示例

```cpp
#include "cppjson.h"

int main() {
    const char* json_str = R"({"name":"C++","year":2026,"tags":["system","AI"]})";
    JsonValue root = parse_json(json_str);
    print_value(root, 0);
    return 0;
}
```

预期输出：

```
{
  "name": "C++",
  "year": 2026,
  "tags": [
    "system",
    "AI"
  ]
}
```

---

## 项目结构

```
.
├── cppjson.cpp         # 主程序与 JSON 库实现
├── cppjson.h           # 核心数据结构与函数声明（规划中）
└── README.md
```

---

## 开发路线图

- [x] 数据模型定义（JsonValue 结构体）
- [x] 带缩进的美观打印（print_value）
- [ ] 完整的 JSON 解析器（parse_value / parse_object / parse_array 等）
- [ ] 增删改查接口（get / set / append / remove）
- [ ] 文件读写（从文件加载 JSON，编辑后保存）
- [ ] 完善的错误报告与错误位置定位
- [ ] 零拷贝高性能优化版本（使用 string_view）

---

## 学习资源

本项目灵感与设计参考了 [cJSON](https://github.com/DaveGamble/cJSON) 的实现方式，并针对 C++ 的现代特性（STL 容器、引用、范围 for 等）进行了改造，适合 C++ 初学者以及希望理解 JSON 内部原理的同学学习。

---

## 许可

MIT License.
