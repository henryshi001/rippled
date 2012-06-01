#ifndef __LOG__
#define __LOG__

#include <sstream>

#include <boost/thread/recursive_mutex.hpp>

enum LogSeverity
{
	lsTRACE		= 0,
	lsDEBUG		= 1,
	lsINFO		= 2,
	lsWARNING	= 3,
	lsERROR		= 4,
	lsFATAL		= 5
};

class Log
{
private:
	Log(const Log&);			// no implementation
	Log& operator=(const Log&);	// no implementation

protected:
	static boost::recursive_mutex sLock;
	static LogSeverity sMinSeverity;

	mutable std::ostringstream oss;
	LogSeverity mSeverity;

public:
	Log(LogSeverity s) : mSeverity(s)
	{ ; }

	~Log();

	template<typename T> std::ostream& operator<<(const T& t) const
	{
		return oss << t;
	}

	static void setMinSeverity(LogSeverity);
};

#endif
