
#pragma  once

#ifndef LAB471_WINDOW_H_INCLUDED
#define LAB471_WINDOW_H_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class EventCallbacks
{

public:


	virtual void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) = 0;

	virtual void mouseCallback(GLFWwindow *window, int button, int action, int mods) = 0;

	virtual void resizeCallback(GLFWwindow *window, int in_width, int in_height) = 0;

};

class WindowManager
{

public:

	WindowManager();
	~WindowManager();

	// Go ahead and ignore these two lines :-) for now
	WindowManager(const WindowManager&) = delete;
	WindowManager& operator= (const WindowManager&) = delete;

	bool init(int const width, int const height);
	void shutdown();

	void setEventCallbacks(EventCallbacks *callbacks);

	GLFWwindow *getHandle();

protected:

	static WindowManager * instance;

	GLFWwindow *windowHandle = nullptr;
	EventCallbacks *callbacks = nullptr;

private:

	static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void mouse_callback(GLFWwindow *window, int button, int action, int mods);
	static void resize_callback(GLFWwindow *window, int in_width, int in_height);

};

#endif
