## class FunctionMapper

Class providing a mapping between integer function codes and associated functions which support the requirements of ModuleInterfaceHandler.  

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

Structure mapping an integer functionCode to an associated handler function.  

---

###### API documentation generated using [Doxygenmd](https://github.com/d99kris/doxygenmd)

