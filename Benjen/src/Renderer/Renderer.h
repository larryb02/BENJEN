#ifndef RENDERER_H
#define RENDERER_H
namespace BENJEN
{
    class Renderer
    {
    private:
        void Init();
    public:
        Renderer(/* args */);
        ~Renderer();

        static void SetColor(float r, float g, float b, float a);
        // draw and indexed draw methods
    };
    

}

#endif
