#pragma once

#include "../../Header/UI/UIElement/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		enum class AnimationType
		{
			FADE_IN,
			FADE_OUT
		};


		class AnimatedImageView : public ImageView
		{
		private:

			//define the callback function type
			using CallbackFunction = std::function<void()>;

			//creating a variable of CallbackFunction
			CallbackFunction callback_function = nullptr;

			void updateElapsedDuration();
			void handleAnimationProgress();
			void updateAnimation();


		protected:

			const float default_animation_duration = 2.0f;

			AnimationType animation_type;
			float elapsed_duration;
			float animation_duration;
			sf::Clock clock;

			virtual void reset();
			void setAnimationDuration(float duration);
			void setAnimationType(AnimationType type);

			virtual void fadeIn();
			virtual void fadeOut();

		public:

			AnimatedImageView();
			~AnimatedImageView();

			virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position) override;
			virtual void update() override;
			virtual void render() override;

			virtual void playAnimation(AnimationType animation_type, float duration, CallbackFunction animation_end_callback);

			void registerCallbackFunction(CallbackFunction animation_end_callback);

		};
	}
}