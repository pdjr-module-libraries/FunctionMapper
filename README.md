# class `FunctionMapper` 

```
class FunctionMapper
  : public ModuleOperatorInterfaceClient
```  

ADT implementing a jump vector.

The class implements a mechanism which supports firmware using the ModuleOperatorInteraction class by allowing a one byte address to trigger execution of an associated function which may take a one byte argument.

Each entry in the jump vector is a pair of the form:

{ unsigned int address, (bool *function)(unsigned char value) }

Entries can be added to the jump vector at instantiation and or dynamically.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`FunctionMapper`](#classFunctionMapper_1a0da0673c8c109e95f1d075b6935cbecd)`(`[`FunctionMap`](#structFunctionMapper_1_1FunctionMap)` * functionMapArray,unsigned int size)` | Construct a new [FunctionMapper](#classFunctionMapper) object.
`public bool `[`addHandler`](#classFunctionMapper_1a8445f7492e82da8fe6dbbb957e9fc931)`(unsigned char functionCode,bool(*)(unsigned char, unsigned char) handler)` | Add a new [FunctionMap](#structFunctionMapper_1_1FunctionMap) to an existing [FunctionMapper](#classFunctionMapper).
`public bool `[`validateAddress`](#classFunctionMapper_1a231f177fee08f712ca4959e1bb93ce55)`(unsigned int functionCode)` | Check that a function code is mapped to a function.
`public bool `[`processValue`](#classFunctionMapper_1a8a437efb9a90f80c661aaf22c07de571)`(unsigned int functionCode,unsigned char value)` | Execute a function.

## Members

#### `public  `[`FunctionMapper`](#classFunctionMapper_1a0da0673c8c109e95f1d075b6935cbecd)`(`[`FunctionMap`](#structFunctionMapper_1_1FunctionMap)` * functionMapArray,unsigned int size)` 

Construct a new [FunctionMapper](#classFunctionMapper) object.

Zero or more FunctionMaps can be added to the [FunctionMapper](#classFunctionMapper) by passing a statically allocated array of FunctionMaps to the constructor. 
```cpp
FunctionMap myFunctionMap[] = {
  { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
  { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
  { 0, 0 }
}

FunctionHandler myFunctionHandler(myFunctionMap);
```

 With a single array argument the [FunctionMapper](#classFunctionMapper) object is sized to exactly accommodate the supplied map array and subsequent use of the `[addHandler()](#classFunctionMapper_1a8445f7492e82da8fe6dbbb957e9fc931)` method is not possible. 
 Optionally the constructor can be passed a second argument which specifies the maximum number of FunctionMaps that can be stored in the new [FunctionMapper](#classFunctionMapper). So long as any supplied function map array has no more than `size` elements, the `[addHandler()](#classFunctionMapper_1a8445f7492e82da8fe6dbbb957e9fc931)` method can be used to dynamically add more maps to the FunctionHandler after instantiation. 
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
* `functionMapArray` - array of [FunctionMap](#structFunctionMapper_1_1FunctionMap) structures (optional, defaults to empty). 

* `size` - maximum number of FunctionMaps that can be saved in this [FunctionMapper](#classFunctionMapper) (optional: defaults to size of *functionMapArray*).

#### `public bool `[`addHandler`](#classFunctionMapper_1a8445f7492e82da8fe6dbbb957e9fc931)`(unsigned char functionCode,bool(*)(unsigned char, unsigned char) handler)` 

Add a new [FunctionMap](#structFunctionMapper_1_1FunctionMap) to an existing [FunctionMapper](#classFunctionMapper).

#### Parameters
* `functionCode` - the value of the map code property. 

* `handler` - the handler function to associate with functionCode. 

#### Returns
true - suceess. 

#### Returns
false - failure (the [FunctionMapper](#classFunctionMapper) was full).

#### `public bool `[`validateAddress`](#classFunctionMapper_1a231f177fee08f712ca4959e1bb93ce55)`(unsigned int functionCode)` 

Check that a function code is mapped to a function.

#### Parameters
* `functionCode` - the functiom code to be checked. 

#### Returns
true - if a [FunctionMap](#structFunctionMapper_1_1FunctionMap) exists with the specified function code. 

#### Returns
false - if there is no [FunctionMap](#structFunctionMapper_1_1FunctionMap) with the specified function code.

#### `public bool `[`processValue`](#classFunctionMapper_1a8a437efb9a90f80c661aaf22c07de571)`(unsigned int functionCode,unsigned char value)` 

Execute a function.

#### Parameters
* `functionCode` - the code of the function to be called. 

* `value` - a value to be passed to the function. 

#### Returns
true - the function returned true (whatever that means). 

#### Returns
false - the function returned false (whatever that means) or *functionCode* was not defined.

# struct `FunctionMapper::FunctionMap` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned int `[`functionCode`](#structFunctionMapper_1_1FunctionMap_1ae62581031d4d9bac8219e1cff35121e9) | 
`public bool(* `[`handler`](#structFunctionMapper_1_1FunctionMap_1a7050c1e20eb24dba37ff380f83edb48a) | 

## Members

#### `public unsigned int `[`functionCode`](#structFunctionMapper_1_1FunctionMap_1ae62581031d4d9bac8219e1cff35121e9) 

#### `public bool(* `[`handler`](#structFunctionMapper_1_1FunctionMap_1a7050c1e20eb24dba37ff380f83edb48a) 

Generated by [Moxygen](https://sourcey.com/moxygen)