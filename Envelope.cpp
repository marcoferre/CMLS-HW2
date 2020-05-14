/*
  ==============================================================================

    Envelope.cpp
    Created: 13 May 2020 1:29:57am
    Author:  marco

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p) :
    processor(p)
{
    setSize(200, 200);

    //slider initialization values
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&attackSlider);
    
    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.8f);
    releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&releaseSlider);
    
    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(1.0f, 2000.0f);
    decaySlider.setValue(1.0f);
    decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&decaySlider);
    
    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0.0f, 1.0f);
    sustainSlider.setValue(0.8f);
    sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&sustainSlider);
    
    //sends value of the slider to the tree state in the processor
    attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
    releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);
    decayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decaySlider);
    sustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", sustainSlider);
}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    Rectangle<int> titleArea(0, 10, getWidth(), 20);
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Envelope", titleArea, Justification::centredTop);

    g.drawText("A", 53, 150, 20, 20, Justification::centredTop);
    g.drawText("D", 77, 150, 20, 20, Justification::centredTop);
    g.drawText("S", 103, 150, 20, 20, Justification::centredTop);
    g.drawText("R", 128, 150, 20, 20, Justification::centredTop);
    
    Rectangle<float> area(25, 25, 150, 150);

    g.setColour(Colours::grey);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Envelope::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(50);

    int sliderWidth = 25;
    int sliderHeight = 175;

    attackSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    decaySlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    sustainSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    releaseSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
}
