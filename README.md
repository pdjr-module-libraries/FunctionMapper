## class FunctionMapper

Class providing a mapping between integer function codes and associated functions which support the requirements of \fCModuleInterfaceHandler.  

---

```c++
FunctionMapper (FunctionMap * functionMapArray, unsigned int size = 0)
```
Construct a new FunctionMapper object. Zero or more FunctionMap definitions can be added to the new FunctionHandler by passing a statically allocated array of FunctionMaps to the constructor. 
 
.nf
{ unparsed} 
FunctionMap myFunctionMap[] = {
  { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
  { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
  { 0, 0 }
}
FunctionHandler myFunctionHandler(myFunctionMap);
.fi
 
 With a single array argument the FunctionMapper object is sized to accommodate the supplied map array and use of the \fCaddHandler() method (see below) is not possible. 
 Optionally the constructor can be passed a second argument which specifies the maximum size of the FunctionHandler and, so long as the supplied array doesn't fill the map, addHandler() can be used to dynamically add more maps to the FunctionHandler after instantiation. 
 
.nf
FunctionMap myFunctionMap[] = {
  { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
  { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
  { 0, 0 }
}
FunctionHandler myFunctionHandler(myFunctionMap, 10);
myFunctionHandler.addHandler(9, [](unsigned char functionCode, unsigned char value)->bool{ return(value > 99); });
bool isBig = myFunctionHandler.process(9, 101);
.fi
 
 

**Parameters**
- `functionMapArray` - array of FunctionMap structures or 0. 
- `size` - the maximum number of FunctionMaps that can be saved in FunctionHandler or zero (the default) to size FunctionHandler so that it can only hold
- `functionMapArray.` 

---

```c++
bool addHandler (unsigned char functionCode, bool(*)(unsigned char, unsigned char) handler)
```
Add a new FunctionMap to an existing FunctionMapper. 

**Parameters**
- `functionCode` - the value of the map code property. 
- `handler` - the handler function to associate with functionCode. 

**Returns:**
- true - suceess. 
- false - failure (the FunctionMapper was full). 

---

```c++
bool processValue (unsigned char functionCode, unsigned char value)
```

**Parameters**
- `functionCode` - the code of the function to be called. 
- `value` - a value to be passed to the function. 

**Returns:**
- true - the function returned true (whatever that means). 
- false - the function returned false (whatever that means). 

---

```c++
bool validateAddress (unsigned char functionCode)
```
Check that a function code is mapped to a function. 

**Parameters**
- `functionCode` - the functiom code to be checked. 

**Returns:**
- true - if a FunctionMap exists with the specified function code. 
- false - if there is no FunctionMap with the specified function code. 

---

## class FunctionMapper::FunctionMap



---

###### API documentation generated using [Doxygenmd](https://github.com/d99kris/doxygenmd)

