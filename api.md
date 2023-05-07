# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`FunctionMapper`](#class_function_mapper) | Class providing a mapping between integer function codes and associated functions which support the requirements of ModuleInterfaceHandler.
`struct `[`FunctionMapper::FunctionMap`](#struct_function_mapper_1_1_function_map) | 

# class `FunctionMapper` 

```
class FunctionMapper
  : public ModuleOperatorInterfaceClient
```  

Class providing a mapping between integer function codes and associated functions which support the requirements of ModuleInterfaceHandler.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`FunctionMapper`](#class_function_mapper_1a3e49c4e7559038ea0a7d3d979fd16431)`(`[`FunctionMap`](#struct_function_mapper_1_1_function_map)` * functionMapArray,unsigned int size)` | Construct a new [FunctionMapper](#class_function_mapper) object.
`public bool `[`addHandler`](#class_function_mapper_1a8445f7492e82da8fe6dbbb957e9fc931)`(unsigned char functionCode,bool(*)(unsigned char, unsigned char) handler)` | Add a new [FunctionMap](#struct_function_mapper_1_1_function_map) to an existing [FunctionMapper](#class_function_mapper).
`public bool `[`validateAddress`](#class_function_mapper_1aeeae983303efa97168866e8ff68cf7c7)`(unsigned char functionCode)` | Check that a function code is mapped to a function.
`public bool `[`processValue`](#class_function_mapper_1abb6078f5a7556add80f6587c5b2d1334)`(unsigned char functionCode,unsigned char value)` | #### Parameters

## Members

#### `public  `[`FunctionMapper`](#class_function_mapper_1a3e49c4e7559038ea0a7d3d979fd16431)`(`[`FunctionMap`](#struct_function_mapper_1_1_function_map)` * functionMapArray,unsigned int size)` 

Construct a new [FunctionMapper](#class_function_mapper) object.

Zero or more FunctionMaps can be added to the new [FunctionMapper](#class_function_mapper) by passing a statically allocated array of FunctionMaps to the constructor. 
```cpp
FunctionMap myFunctionMap[] = {
  { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
  { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
  { 0, 0 }
}

FunctionHandler myFunctionHandler(myFunctionMap);
```

 With a single array argument the [FunctionMapper](#class_function_mapper) object is sized to exactly accommodate the supplied map array and subsequent use of the `[addHandler()](#class_function_mapper_1a8445f7492e82da8fe6dbbb957e9fc931)` method is not possible. 
 Optionally the constructor can be passed a second argument which specifies the maximum number of FunctionMaps that can be stored in the new [FunctionMapper](#class_function_mapper). So long as any supplied function map array has no more than `size` elements, the `[addHandler()](#class_function_mapper_1a8445f7492e82da8fe6dbbb957e9fc931)` method can be used to dynamically add more maps to the FunctionHandler after instantiation. 
```cpp
FunctionMap myFunctionMap[] = {
  { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
  { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
  { 0, 0 }
}

FunctionHandler myFunctionHandler(myFunctionMap, 10);

myFunctionHandler.addHandler(9, [](unsigned char functionCode, unsigned char value)->bool{ return(value > 99); });

bool isBig = myFunctionHandler.process(9, 101);
```

#### Parameters
* `functionMapArray` - array of [FunctionMap](#struct_function_mapper_1_1_function_map) structures or 0. 

* `size` - the maximum number of FunctionMaps that can be saved in FunctionHandler or zero (the default) to size FunctionHandler so that it can only hold

* `functionMapArray.`

#### `public bool `[`addHandler`](#class_function_mapper_1a8445f7492e82da8fe6dbbb957e9fc931)`(unsigned char functionCode,bool(*)(unsigned char, unsigned char) handler)` 

Add a new [FunctionMap](#struct_function_mapper_1_1_function_map) to an existing [FunctionMapper](#class_function_mapper).

#### Parameters
* `functionCode` - the value of the map code property. 

* `handler` - the handler function to associate with functionCode. 

#### Returns
true - suceess. 

#### Returns
false - failure (the [FunctionMapper](#class_function_mapper) was full).

#### `public bool `[`validateAddress`](#class_function_mapper_1aeeae983303efa97168866e8ff68cf7c7)`(unsigned char functionCode)` 

Check that a function code is mapped to a function.

#### Parameters
* `functionCode` - the functiom code to be checked. 

#### Returns
true - if a [FunctionMap](#struct_function_mapper_1_1_function_map) exists with the specified function code. 

#### Returns
false - if there is no [FunctionMap](#struct_function_mapper_1_1_function_map) with the specified function code.

#### `public bool `[`processValue`](#class_function_mapper_1abb6078f5a7556add80f6587c5b2d1334)`(unsigned char functionCode,unsigned char value)` 

#### Parameters
* `functionCode` - the code of the function to be called. 

* `value` - a value to be passed to the function. 

#### Returns
true - the function returned true (whatever that means). 

#### Returns
false - the function returned false (whatever that means).

# struct `FunctionMapper::FunctionMap` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned int `[`functionCode`](#struct_function_mapper_1_1_function_map_1ae62581031d4d9bac8219e1cff35121e9) | 
`public bool(* `[`handler`](#struct_function_mapper_1_1_function_map_1a7050c1e20eb24dba37ff380f83edb48a) | 

## Members

#### `public unsigned int `[`functionCode`](#struct_function_mapper_1_1_function_map_1ae62581031d4d9bac8219e1cff35121e9) 

#### `public bool(* `[`handler`](#struct_function_mapper_1_1_function_map_1a7050c1e20eb24dba37ff380f83edb48a) 

Generated by [Moxygen](https://sourcey.com/moxygen)