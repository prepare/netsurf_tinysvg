/* alpha blend two pixels together */
static inline nsfb_colour_t 
nsfb_plot_ablend(nsfb_colour_t pixel, nsfb_colour_t scrpixel)
{
    int opacity = pixel >> 24;
    int transp = 0x100 - opacity;
    uint32_t rb, g;

    rb = ((pixel & 0xFF00FF) * opacity +
          (scrpixel & 0xFF00FF) * transp) >> 8;
    g  = ((pixel & 0x00FF00) * opacity +
          (scrpixel & 0x00FF00) * transp) >> 8;

    return (rb & 0xFF00FF) | (g & 0xFF00);
}


bool nsfb_plot_clip(const nsfb_bbox_t * restrict clip, nsfb_bbox_t * restrict rect);

bool nsfb_plot_clip_ctx(nsfb_t *nsfb, nsfb_bbox_t * restrict rect);

bool nsfb_plot_clip_line(const nsfb_bbox_t * restrict clip, nsfb_bbox_t * restrict line);

bool nsfb_plot_clip_line_ctx(nsfb_t *nsfb, nsfb_bbox_t * restrict line);
