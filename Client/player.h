#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "animation.h"

class Player {
	private:
		const float SPEED_RUN = 100.0f;


	public:
		enum class Facing {
			Up, Down, Left, Right
		};

		Player(Atlas* atlas_idle_up, Atlas* atlas_idle_down, Atlas* atlas_idle_left, Atlas* atlas_idle_right, Atlas* atlas_run_up,
			Atlas* atlas_run_down, Atlas* atlas_run_left, Atlas* atlas_run_right){ 
		
			anim_idle_up.set_loop(true);
			anim_idle_up.set_interval(0.1f);
			anim_idle_up.add_frame(atlas_idle_up);

			anim_idle_down.set_loop(true);
			anim_idle_down.set_interval(0.1f);
			anim_idle_down.add_frame(atlas_idle_down);

			anim_idle_left.set_loop(true);
			anim_idle_left.set_interval(0.1f);
			anim_idle_left.add_frame(atlas_idle_left);

			anim_idle_right.set_loop(true);
			anim_idle_right.set_interval(0.1f);
			anim_idle_right.add_frame(atlas_idle_right);

			anim_run_up.set_loop(true);
			anim_run_up.set_interval(0.1f);
			anim_run_up.add_frame(atlas_run_up);

			anim_run_down.set_loop(true);
			anim_run_down.set_interval(0.1f);
			anim_run_down.add_frame(atlas_run_down);

			anim_run_left.set_loop(true);
			anim_run_left.set_interval(0.1f);
			anim_run_left.add_frame(atlas_run_left);

			anim_run_right.set_loop(true);
			anim_run_right.set_interval(0.1f);
			anim_run_right.add_frame(atlas_run_right);
		
		}

		void on_update(float delta) {
			if (!position.approx(pos_target)) {
				velocity = (pos_target - position).Normalize() * SPEED_RUN;
			}
			else velocity = Vector2(0, 0);

			if ((pos_target - position).Length() <= (velocity * delta).Length()) {
				position = pos_target;
			}
			else position += velocity * delta;


			if (velocity.approx(Vector2(0, 0))) {
				switch (facing) {
				case Facing::Up: current_anim = &anim_idle_up; break;
				case Facing::Down: current_anim = &anim_idle_down; break;
				case Facing::Left: current_anim = &anim_idle_left; break;
				case Facing::Right: current_anim = &anim_idle_right; break;
				}
			}
			else {
				if (abs(velocity.y) >= 0.0001f) {
					facing = (velocity.y > 0) ? Facing::Down : Facing::Up;
				}
				if (abs(velocity.x) >= 0.0001f) {
					facing = (velocity.x > 0) ? Facing::Right : Facing::Left;
				}

				switch (facing) {
				case Facing::Up: current_anim = &anim_run_up; break;
				case Facing::Down: current_anim = &anim_run_down; break;
				case Facing::Left: current_anim = &anim_run_left; break;
				case Facing::Right: current_anim = &anim_run_right; break;
				}
			}
			
			if (!current_anim) return;
			current_anim->set_position(position);
			current_anim->on_update(delta);
		}
		~Player() = default;
		
		void on_render(const Camera& camera) {
			if (!current_anim) return;
			current_anim->on_render(camera);
 		}

		void set_position(const Vector2& position) {
			this->position = position;
		}

		const Vector2& get_position() {
			return position;
		}

		void set_target(const Vector2& pos_target) {
			this->pos_target = pos_target;
		}

	private:
		Vector2 position;
		Vector2 pos_target;
		Vector2 velocity;

		Animation anim_idle_up;
		Animation anim_idle_down;
		Animation anim_idle_left;
		Animation anim_idle_right;
		Animation anim_run_up;
		Animation anim_run_down;
		Animation anim_run_left;
		Animation anim_run_right;
		Animation* current_anim;

		Facing facing = Facing::Down;	
};
#endif //!__PLAYER_H_
