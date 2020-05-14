/*
  ==============================================================================

    Oscillator.h
    Created: 13 May 2020 12:31:18am
    Author:  marco

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator    : public Component,
                      private ComboBox::Listener
{
public:
    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu;

    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
