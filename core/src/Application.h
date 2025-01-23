#ifndef APPLICATION_H
#define APPLICATION_H

namespace BENJEN
{
    class Application
    {
    private:
        bool m_running = true;
    public:
        Application();
        ~Application();

        void Run();
        void OnUpdate();
        void onDetach(); // onDetach or onExit
    };

}
#endif
