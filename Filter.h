/*
  ==============================================================================

    Filter.h
    Created: 13 May 2020 11:31:28am
    Author:  marco

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter(SynthFrameworkAudioProcessor&);
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider filterCutoff;
    Slider filterRes;

    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resVal;



    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
