/*
 * NullSwapChain.cpp
 *
 * Copyright (c) 2015 Lukas Hermanns. All rights reserved.
 * Licensed under the terms of the BSD 3-Clause license (see LICENSE.txt).
 */

#include "NullSwapChain.h"


namespace LLGL
{


static Format ChooseColorFormat(int /*colorBits*/)
{
    return Format::RGBA8UNorm;
}

static Format ChooseDepthStencilFormat(int depthBits, int stencilBits)
{
    if (depthBits == 32)
    {
        if (stencilBits != 0)
            return Format::D32FloatS8X24UInt;
        else
            return Format::D32Float;
    }
    else
    {
        if (stencilBits != 0)
            return Format::D24UNormS8UInt;
        else
            return Format::D32Float;
    }
}

NullSwapChain::NullSwapChain(const SwapChainDescriptor& desc, const std::shared_ptr<Surface>& surface) :
    SwapChain           { desc                                                       },
    samples_            { desc.samples                                               },
    colorFormat_        { ChooseColorFormat(desc.colorBits)                          },
    depthStencilFormat_ { ChooseDepthStencilFormat(desc.depthBits, desc.stencilBits) }
{
    SetOrCreateSurface(surface, desc.resolution, desc.fullscreen, nullptr);
}

void NullSwapChain::SetName(const char* name)
{
    if (name != nullptr)
        label_ = name;
    else
        label_.clear();
}

void NullSwapChain::Present()
{
    // dummy
}

std::uint32_t NullSwapChain::GetSamples() const
{
    return samples_;
}

Format NullSwapChain::GetColorFormat() const
{
    return colorFormat_;
}

Format NullSwapChain::GetDepthStencilFormat() const
{
    return depthStencilFormat_;
}

bool NullSwapChain::SetVsyncInterval(std::uint32_t vsyncInterval)
{
    vsyncInterval_ = vsyncInterval;
    return true;
}

const RenderPass* NullSwapChain::GetRenderPass() const
{
    return renderPass_;
}

bool NullSwapChain::ResizeBuffersPrimary(const Extent2D& /*resolution*/)
{
    return true;
}


} // /namespace LLGL



// ================================================================================
