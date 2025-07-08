#ifndef _PATH_H_
#define _PATH_H

#include "vector2.h"

#include <vector>

class Path {
	private:
		float total_length;
		std::vector<Vector2> point_list;
		std::vector<float> segment_len_list;

public:
	Path(const std::vector<Vector2>& point_list) {
		this->point_list = point_list;

		for (size_t i = 1; i < point_list.size(); i++) {
			float segment_len = (point_list[i] - point_list[i-1]).Length();
			segment_len_list.push_back(segment_len);
			total_length += segment_len;
		}
	}

	~Path() = default;

	Vector2 get_position_at_progress(float progress) const {
		if (progress <= 0.0f) return point_list.front();
		if (progress >= 1.0f) return point_list.back();

		float target_distance = progress * total_length;

		float accumulate_len = 0.0f;
		for (size_t i = 0; i < point_list.size(); i++) {
			accumulate_len += segment_len_list[i];
			if (accumulate_len >= target_distance) {
				float segment_progress = (target_distance - (accumulate_len - segment_len_list[i])) / segment_len_list[i];
				return point_list[i - 1] + (point_list[i] - point_list[i-1])*segment_progress;
			}
		}
		return point_list.back();
	}




























 };



















#endif // !_PATH_H_