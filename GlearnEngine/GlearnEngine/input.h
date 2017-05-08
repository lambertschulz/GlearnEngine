#ifndef _INPUT_H
#define _INPUT_H

namespace GlearnInput {
	class Input{
	public:
		Input();
		Input(const Input&);
		~Input();

		void Init();

		void KeyDown(unsigned int);
		void KeyUp(unsigned int);

		bool IsKeyDown(unsigned int);

	private:
		bool m_keys[256];
	};
}
#endif // !_INPUT_H
