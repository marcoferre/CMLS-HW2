/*
  ==============================================================================

    Filter.cpp
    Created: 13 May 2020 11:31:28am
    Author:  marco

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Filter.h"

//==============================================================================
Filter::Filter(SynthFrameworkAudioProcessor& p) :
    processor(p)
{
    setSize(200, 200);

    filterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterCutoff.setRange(40.0, 20000.0);
    filterCutoff.setValue(1000.0);
    filterCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filterCutoff);
    filterVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterCutoff", filterCutoff);
    filterCutoff.setSkewFactorFromMidPoint(1000.0);

    filterRes.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterRes.setRange(1, 5);
    filterRes.setValue(1);
    filterRes.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filterRes);
    resVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRes", filterRes);
}

Filter::~Filter()
{
}

void Filter::paint (Graphics& g)
{
    Rectangle<int> titleArea(0, 10, getWidth(), 20);

    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);


    Rectangle<float> area(25, 25, 150, 150);

    g.setColour(Colours::grey);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
    g.setColour(Colours::white);
    g.drawText("cutoff", 30, 150, 70, 20, Justification::centredTop);
    g.drawText("resonance", 100, 150, 70, 20, Justification::centredTop);
}

void Filter::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);

    filterCutoff.setBounds(30, 70, 70, 70);
    filterRes.setBounds(100, 70, 70, 70);
}
