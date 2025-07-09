use charming::{
    component::{Axis, Grid, Title}, 
    element::{AxisLabel, AxisType, NameLocation, TextStyle}, 
    series::Line, 
    theme::Theme, 
    Chart, ImageRenderer
};
use rand::Rng;

fn gen_pitch_values() -> Vec<f32> {
    let mut rng = rand::rng();
    let mut pitch_values = Vec::new();

    let mut pitch = 15.0 as f32;
    let decay_rate = 0.85 as f32;
    let noise_level = 0.2 as f32;

    for _ in 0..30 {
        pitch *= decay_rate;

        let noise: f32 = rng.random_range(-noise_level..=noise_level);
        let noisy_pitch = pitch + noise;

        pitch_values.push(noisy_pitch);
    }

    pitch_values

}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let pitch_data = gen_pitch_values();

    let font = TextStyle::new().font_size(50);


    let chart = Chart::new()
        .title(
            Title::new()
            .text("IMU PID Response")
            .padding(5.0)
            .left("center")
            .text_style(TextStyle::new().font_size(100)), 
        )
        .grid(
            Grid::new()
            .bottom("10%")
            .top("5%")
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
            .min(0.0)
            .max(15)
            .name_location(NameLocation::Middle)
            .name_gap(40)
            .name_text_style(TextStyle::new().font_size(40))
            .axis_label(AxisLabel::new().font_size(40)), 
        )
        .series(Line::new().name("Pitch").data(pitch_data));

    let mut renderer = ImageRenderer::new(3000, 2400).theme(Theme::Wonderland);
    renderer.save(&chart, "pid.svg")?;

    Ok(())
}
