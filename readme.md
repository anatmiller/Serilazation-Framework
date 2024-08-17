  ## Seralization Framework
  
  Serialization Framework
  This repository contains a C++ serialization framework designed to handle the storage and restoration of a list of instances derived from a Base class. The framework is implemented with virtual inheritance, ensuring flexibility and ease of use without requiring objects to have any knowledge of the underlying file format.
  
  ## Overview
  The Serialization Framework is designed to:
  
  Store and restore any list of instances derived from the Base class.
  Abstract file format details away from the objects, ensuring that they do not require any knowledge about the storage mechanism.
  Provide a generic and reusable solution for serializing any class derived from Base without needing additional changes to the serialization framework.
  Features
  OutArchive and InArchive classes to handle writing and reading of objects to and from files.
  Generic reader and writer functions to support serialization of Base and its derivatives.
  Support for virtual inheritance, allowing for polymorphic serialization and deserialization of objects.
  
  ## OutArchive & InArchive
  OutArchive handles writing serialized data to a file.
  InArchive handles reading serialized data from a file.
  These classes manage the underlying file operations and ensure that the objects are correctly serialized and deserialized.
  
  ## Implementation Notes
  The serialization framework is designed to be extensible, allowing for the easy addition of new classes derived from Base.
  Helper functions or classes can be implemented to manage more complex serialization logic, as needed.
  Building and Running
  To build and run the sample provided in the repository:
  
  Clone the repository.
  Compile the code using your preferred C++ compiler.
  Run the main() function to see the serialization and deserialization in action.
  License
  This project is licensed under the MIT License - see the LICENSE file for details.
  
