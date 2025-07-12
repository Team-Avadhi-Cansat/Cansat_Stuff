use charming::{
    component::{Axis, Grid, Title},
    element::{AxisLabel, AxisType, LineStyle, NameLocation, TextStyle},
    series::Line,
    theme::Theme,
    Chart, ImageRenderer,
};
use rand::Rng;

fn gen_pitch_values() -> Vec<f32> {
    let mut rng = rand::rng();
    let mut pitch_values = Vec::new();

    let mut pitch = 90.0_f32;
    let decay_rate = 0.85_f32;
    let noise_level = 3.0_f32;

    for _ in 0..30 {
        pitch *= decay_rate;
        let noise: f32 = rng.random_range(-noise_level..=noise_level);
        pitch_values.push(pitch + noise);
    }

    pitch_values
}

fn gen_damped_oscillation() -> Vec<f32> {
    let mut values = Vec::new();
    let decay = 0.9_f32;
    let amplitude = 90.0_f32;
    let frequency = 0.25 * std::f32::consts::PI;

    for t in 0..30 {
        let value = amplitude * (decay.powi(t)) * (frequency * t as f32).sin();
        values.push(value);
    }

    values
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let pitch_data = gen_pitch_values();
    let damped_data = gen_damped_oscillation();

    let font = TextStyle::new().font_size(50);

    let chart = Chart::new()
        .title(
            Title::new()
                .text("Damped Oscillation Centered at 0°")
                .padding(5.0)
                .left("center")
                .text_style(TextStyle::new().font_size(100)),
        )
        .grid(
            Grid::new()
                .bottom("10%")
                .top("5%"),
        )
        .x_axis(
            Axis::new()
                .type_(AxisType::Category)
                .name("Time")
                .name_location(NameLocation::Middle)
                .name_gap(60)
                .max(29)
                .name_text_style(font.clone())
                .axis_label(AxisLabel::new().font_size(40)),
        )
        .y_axis(
            Axis::new()
                .type_(AxisType::Value)
                .name("Pitch (°)")
                .min(-90.0)
                .max(90.0)
                .split_number(20)
                .name_location(NameLocation::Middle)
                .name_gap(40)
                .name_text_style(TextStyle::new().font_size(40))
                .axis_label(AxisLabel::new().font_size(40)),
        )
        .series(Line::new().name("PID Pitch").data(pitch_data))
        .series(
            Line::new()
                .name("Damped Oscillation")
                .data(damped_data)
                .line_style(LineStyle::new().color("#e91e63").width(5.0)),
        );

    let mut renderer = ImageRenderer::new(3000, 2400).theme(Theme::Wonderland);
    renderer.save(&chart, "centered_damped_oscillation.svg")?;

    Ok(())
}
