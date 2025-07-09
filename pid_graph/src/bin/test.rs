use charming::{
    component::Legend,
    element::ItemStyle,
    series::{Pie, PieRoseType},
    Chart, ImageRenderer
};


fn main() {
    let chart = Chart::new()
        .legend(Legend::new().top("bottom"))
        .series(
            Pie::new()
            .name("Nighingale Chart")
            .rose_type(PieRoseType::Radius)
            .radius(vec!["50", "150"])
            .center(vec!["50%", "50%"])
            .item_style(ItemStyle::new().border_radius(8))
            .data(vec![
                (40.0, "rose 1"),
                (38.0, "rose 2"),
                (32.0, "rose 3"),
            ]),
        );

    let mut renderer = ImageRenderer::new(1000, 800);
    renderer.save(&chart, "chart.svg");
}
