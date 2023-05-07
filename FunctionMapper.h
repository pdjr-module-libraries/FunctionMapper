#ifndef FUNCTION_MAPPER_H
#define FUNCTION_MAPPER_H

#include <ModuleOperatorInterfaceClient.h>

/**
 * @brief Class providing a processing interface and storage for an
 * arbitrary number of FunctionMaps.
 * \n 
 * A FunctionMap implements a mapping between an integer function code
 * and a function which complies with the requirements of
 * ModuleInterfaceHandler.
 * The following example shows a FunctionMap associating function code
 * (0) with an anonymous lambda function.
 * \n 
 * @code{.unparsed}
 * { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } }
 * @endcode
 * \n 
 */
class FunctionMapper: public ModuleOperatorInterfaceClient {
  
  public:

    /**
     * @brief Structure mapping an integer function code to an
     * associated handler function.
     * @var functionCode - a unique integer value identifying the associated function.
     * @var handler - \p ModuleOperatorInterfaceHandler function.
     */
    typedef struct { unsigned int functionCode; bool (*handler)(unsigned char, unsigned char); } FunctionMap;
    
    /**
     * @brief Construct a new FunctionMapper object.
     * 
     * Zero or more FunctionMaps can be added to the new FunctionMapper
     * by passing a statically allocated array of FunctionMaps to the
     * constructor.
     * \n 
     * @code{.unparsed}
     * FunctionMap myFunctionMap[] = {
     *   { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
     *   { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
     *   { 0, 0 }
     * }
     * 
     * FunctionHandler myFunctionHandler(myFunctionMap);
     * @endcode
     * \n 
     * With a single array argument the FunctionMapper object is sized
     * to exactly accommodate the supplied map array and subsequent use
     * of the \p addHandler() method is not possible.
     * \n 
     * Optionally the constructor can be passed a second argument which
     * specifies the maximum number of FunctionMaps that can be stored
     * in the new FunctionMapper.
     * So long as any supplied function map array has no more than
     * \p size elements, the \p addHandler() method can be used to
     * dynamically add more maps to the FunctionHandler after
     * instantiation.
     * \n 
     * @code
     * FunctionMap myFunctionMap[] = {
     *   { 0, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 0); } },
     *   { 1, [](unsigned char functionCode, unsigned char value)->bool{ return((value % 2) == 1); } },
     *   { 0, 0 }
     * }
     * 
     * FunctionHandler myFunctionHandler(myFunctionMap, 10);
     * 
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
