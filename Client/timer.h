#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>

class Timer {
private:
	std::function<void()> on_timeout;
	float pass_time = 0;
	float wait_time = 0;
	bool paused = false;
	bool shotted = false;
	bool one_shot = false;

public:
	Timer() = default;
	~Timer() = default;

	void restart() {
		pass_time = 0;
		shotted = false;
	}

	void set_wait_time(float val) {
		wait_time = val;
	}

	void set_one_shot(bool flag) {
		one_shot = flag;
	}

	void set_on_timeout(std::function<void()> on_timeout) {
		this->on_timeout = std::move(on_timeout);
	}

	void pause() {
		paused = true;
	}

	void resume() {
		paused = false;
	}

	void on_update(float delat) {
		if (paused) return;

		pass_time += delat;
		if (pass_time >= wait_time) {
			bool can_shot = (!one_shot || (one_shot && !shotted));
			shotted = true;
			if (can_shot && on_timeout)
				on_timeout();
			pass_time -= wait_time;
		}
	}
};
#endif //!_TIMER_H_
