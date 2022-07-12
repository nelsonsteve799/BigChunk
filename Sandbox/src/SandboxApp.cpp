#include <BigChunk.h>

class Sandbox : public BigChunk::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

BigChunk::Application* CreateApplication() {

	return new Sandbox();
}