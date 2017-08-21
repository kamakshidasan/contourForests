/// \defgroup baseCode baseCode
/// \brief Base code processing packages.
/// @{
/// \class wtfit::Debug
/// \date February 2011.
/// 
/// \brief Minimalist debugging class.
///
/// %Debug provides a few mechanisms to handle debugging messages at a global
/// and local scope, time and memory measurements, etc.
/// Each wtfit class should inheritate from it.

#ifndef                 _DEBUG_H
#define                 _DEBUG_H

#ifdef withOpenMP
  #include              <omp.h>
#endif

#include                <cerrno>
#include                <fstream>
#include                <iostream>
#include                <sstream>
#include                <string>
#include                <vector>


using namespace std;

namespace wtfit{

  extern bool welcomeMsg_;
  extern bool goodbyeMsg_;
  extern int globalDebugLevel_;
 
  class Wrapper;
  
  class Debug{
    
    public:
      
      // 1) constructors, destructors, operators, etc.
      Debug();
      
      virtual ~Debug();
      
      enum debugPriority{
        fatalMsg,         // 0
        timeMsg,          // 1
        memoryMsg,        // 2
        infoMsg,          // 3
        detailedInfoMsg,  // 4
        advancedInfoMsg   // 5
      };
      
      // 2) functions
      /// Send a debug message to a stream with a priority debugLevel (lower 
      /// means higher priority).
      /// If the global debug level for the program is set to 0, the program
      /// should be completely quiet. So the '0' priority should only be 
      /// reserved for fatal errors.
      /// \param stream Output stream.
      /// \param msg %Debug message (can contain std::endl characters).
      /// \param debugLevel Priority of the message.
      /// \return Returns 0 upon success, negative values otherwise.
      /// \sa msg(), err()
      virtual const int dMsg(ostream &stream, string msg, 
        const int &debugLevel = infoMsg) const;
      
      /// Wrapper for dMsg() that sends a debug message to the standard error
      /// output stream.
      /// \return Returns 0 upon success, negative values otherwise.
      /// \sa dMsg(), msg()
      const int err(const string msg, const int &debugLevel = infoMsg) const;
     
      /// Wrapper for dMsg() that sends a debug message to the standard 
      /// output stream.
      /// \return Returns 0 upon success, negative values otherwise.
      /// \sa dMsg(), msg()
      const int msg(const char *msg, const int &debugLevel = infoMsg) const;
     
      /// Set the debug level of a particular object. The global variable 
      /// globalDebugLevel_ will over-ride this setting if it has a lower value.
      /// \return Returns 0 upon success, negative values otherwise.
      virtual const int setDebugLevel(const int &debugLevel);
      
      int setThreadNumber(const int threadNumber){
        
        threadNumber_ = threadNumber;
        return 0;
      }
      
      /// Specify a pointer to a calling object that wraps the current class 
      /// deriving from wtfit::Debug.
      /// 
      /// This function is useful to pass the execution context (debug level,
      /// number of threads, etc.) from a wrapper to a baseCode object.
      /// \param wrapper Pointer to the wrapping object.
      /// \return Returns 0 upon success, negative values otherwise.
      /// \sa vtkBlank
      int setWrapper(const Wrapper *wrapper);
      
      
    protected:
      
      bool                    lastObject_;
      mutable int             debugLevel_, threadNumber_;
      Wrapper                 *wrapper_;
  };
}

using namespace wtfit;

#include                <Os.h>

/// \brief Legacy backward compatibility
class DebugTimer : public Timer{};
/// \brief Legacy backward compatibility.
class DebugMemory : public Memory{};

#endif
/// @}
