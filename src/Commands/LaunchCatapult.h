#ifndef LaunchCatapult_H
#define LaunchCatapult_H

#include "CommandBase.h"

class LaunchCatapult : public CommandBase {
public:
	LaunchCatapult();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LaunchCatapult_H
