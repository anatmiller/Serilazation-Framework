## Seralization Framework

This repository contains a C++ serialization framework designed to handle the storage and restoration of a list of instances derived from a Base class. The framework is implemented with virtual inheritance, ensuring flexibility and ease of use without requiring objects to have any knowledge of the underlying file format.

Overview
The Serialization Framework is designed to:

Store and restore any list of instances derived from the Base class.
Abstract file format details away from the objects, ensuring that they do not require any knowledge about the storage mechanism.
Provide a generic and reusable solution for serializing any class derived from Base without needing additional changes to the serialization framework.
