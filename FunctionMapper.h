#ifndef FUNCTION_MAPPER_H
#define FUNCTION_MAPPER_H

#include <ModuleOperatorInterfaceClient.h>

/**
 * @brief Class providing a mapping between integer function codes and
 * associated functions which support the requirements of
 * \p ModuleInterfaceHandler.
 */
class FunctionMapper: public ModuleOperatorInterfaceClient {
  
  public:

    /**
     * @brief Structure mapping an integer functionCode to an associated
     * handler function.
     *
     * @var functionCode - a unique integer value identifying the associated function.
     * @var handler - \p ModuleInterfaceHandler function.
     */
    typedef struct { unsigned int functionCode; bool (*handler)(unsigned char, unsigned char); } FunctionMap;
    
    /**
     * @brief Construct a new FunctionMapper object.
     * 
     * Zero or more FunctionMap definitions can be added to the new
     * FunctionHandler by passing a statically allocated array of
     * FunctionMaps to the constructor.
     * \n 
     * @code{, unparsed}
     * FunctionMap myFunctionMap[] = {
     *   { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
     *   { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
     *   { 0, 0 }
     * }
     * FunctionHandler myFunctionHandler(myFunctionMap);
     * @endcode
     * \n 
     * With a single array argument the FunctionMapper object is sized
     * to accommodate the supplied map array and use of the \p addHandler()
     * method (see below) is not possible.
     * \n 
     * Optionally the constructor can be passed a second argument which
     * specifies the maximum size of the FunctionHandler and, so long
     * as the supplied array doesn't fill the map, addHandler() can be
     * used to dynamically add more maps to the FunctionHandler after
     * instantiation.
     * \n 
     * @code
     * FunctionMap myFunctionMap[] = {
     *   { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
     *   { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
     *   { 0, 0 }
     * }
     * FunctionHandler myFunctionHandler(myFunctionMap, 10);
     * myFunctionHandler.addHandler(9, [](unsigned char functionCode, unsigned char value)->bool{ return(value > 99); });
     * 
     * bool isBig = myFunctionHandler.process(9, 101);
     * @endcode
     * \n 
     * @param functionMapArray - array of FunctionMap structures or 0.
     * @param size - the maximum number of FunctionMaps that can be
     * saved in FunctionHandler or zero (the default) to size
     * FunctionHandler so that it can only hold @param functionMapArray. 
     */
    FunctionMapper(FunctionMap *functionMapArray, unsigned int size = 0);

    /**
     * @brief Add a new FunctionMap to an existing FunctionMapper.
     * 
     * @param functionCode - the value of the map code property. 
     * @param handler - the handler function to associate with functionCode.
     * @return true - suceess.
     * @return false - failure (the FunctionMapper was full).
     */
    bool addHandler(unsigned char functionCode, bool (*handler)(unsigned char, unsigned char));

    /**
     * @brief Check that a function code is mapped to a function.
     * 
     * @param functionCode - the functiom code to be checked.
     * @return true        - if a FunctionMap exists with the specified function code.
     * @return false       - if there is no FunctionMap with the specified function code.
     */
    bool validateAddress(unsigned char functionCode);

    /**
     * @brief 
     * 
     * @param functionCode - the code of the function to be called.
     * @param value        - a value to be passed to the function.
     * @return true        - the function returned true (whatever that means).
     * @return false       - the function returned false (whatever that means).
     */
    bool processValue(unsigned char functionCode, unsigned char value);

  private:
    unsigned int arraySize;
    FunctionMap *functionMapArray;

};

#endif
