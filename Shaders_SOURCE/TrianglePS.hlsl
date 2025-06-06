#include "Samplers.hlsli"

struct VSInput
{
    float3 pos : POSITION;
    float4 color : COLOR;
};

struct VSOutput
{
    float4 pos : SV_Position;
    float4 color : COLOR;
};


float4 main(VSOutput output) : SV_TARGET
{
    return output.color;
}