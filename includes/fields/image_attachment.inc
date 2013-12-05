<?php
// add default fields to the hook filter
add_filter('qw_fields', 'qw_field_image_attachment');

/*
 * Add field to qw_fields
 */
function qw_field_image_attachment($fields){

  $fields['image_attachment'] = array(
    'title' => 'Image Attachment',
    'description' => 'Image files that are attached to a post.',
    'output_callback' => 'qw_theme_image', // in theme.inc
    'output_arguments' => true,
    'form_callback' => 'qw_field_image_attachment_form',
  );
  return $fields;
}

/*
 * Image attachment settings
 */
function qw_field_image_attachment_form($field)
{
  $image_sizes = get_intermediate_image_sizes();
  $featured_image = (isset($field['values']['featured_image'])) ? 'checked="checked"' : "";
  ?>
    <!-- image display -->
    <label class="qw-label">Number of items to show:</label>
    <input class="qw-text-short"
           type="text"
           name='<?php print $field['form_prefix']; ?>[image_display_count]'
           value="<?php print ($field['values']['image_display_count']) ? $field['values']['image_display_count']: 0;?>" />
    <p>
      <label>
        <input
          type="checkbox"
          name="<?php print $field['form_prefix']; ?>[featured_image]"
          <?php print $featured_image; ?> /> Featured Image Only
      </label>
    </p>
    <p>
      <label class="qw-label">Image Display Style:</label>
      <select class='qw-js-title' name='<?php print $field['form_prefix']; ?>[image_display_style]'>
        <?php
          foreach($image_sizes as $key => $size)
          {
            $size_selected = ($field['values']['image_display_style'] == $size) ? 'selected="selected"' : '';
            ?>
              <option value="<?php print $size; ?>" <?php print $size_selected; ?>><?php print $size; ?></option>
            <?php
          }
        ?>
      </select>
    </p>
  <?php
}