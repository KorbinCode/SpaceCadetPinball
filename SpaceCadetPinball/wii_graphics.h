#pragma once

#include <3ds.h>
#include <citro3d.h>

#define DISPLAY_TRANSFER_FLAGS                                                                     \
    (GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) |               \
     GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
     GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

class wii_graphics
{
private:
    static C3D_RenderTarget *target;

    static DVLB_s *vshader_dvlb;
    static shaderProgram_s program;
    static int8_t uLoc_projection;
    static int8_t uLoc_modelView;
    static int8_t uLoc_uvOffset;
    static C3D_Mtx projection;
    static void *vbo_data;

public:
    static void Initialize();
    static void Dispose();
    static void BeginRender();
    static void FinishRender();
    static bool IsMainLoopRunning();
    static void SetOrthoProjectionMatrix(float left, float right, float bottom, float top, float near, float far);
    static void SetModelViewMatrix(float x, float y, float w, float h);
    static void DrawQuad(float x, float y, float w, float h, float uvX, float uvY, float uvW, float uvH);
    static void CreateTextureObject(C3D_Tex *textureObject, uint16_t width, uint16_t height, GPU_TEXCOLOR format, GPU_TEXTURE_WRAP_PARAM wrap, GPU_TEXTURE_FILTER_PARAM filter);
    static void UploadTextureObject(C3D_Tex *textureObject, uint8_t *textureData);
    static void BindTextureObject(C3D_Tex *textureObject, int32_t mapIndex);
    static uint32_t GetTextureSize(uint16_t width, uint16_t height, GPU_TEXCOLOR format, int32_t maxLevel);
};