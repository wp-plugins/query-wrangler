<?php
// add default fields to the hook filter
add_filter('qw_fields', 'qw_field_file_attachment');

// add default file styles to the filter
add_filter('qw_file_styles', 'qw_default_file_styles', 0);

/*
 * Add field to qw_fields
 */
function qw_field_file_attachment($fields){

  $fields['file_attachment'] = array(
    'title' => 'File Attachment',
    'description' => 'Files that are attached to a post.',
    'output_callback' => 'qw_theme_file', // in theme.inc
    'output_arguments' => true,
    'form_callback' => 'qw_field_file_attachment_form',
  );
  return $fields;
}

/*
 * File Styles
 *
 * @return array of file styles
 */
function qw_default_file_styles($file_styles)
{
  $file_styles['link'] = array(
    'description' => 'Filename Link to File',
  );
  $file_styles['link_url'] = array(
    'description' => 'URL Link to File',
  );
  $file_styles['url'] = array(
    'description' => 'URL of File',
  );

  return $file_styles;
}

/*
 * File attachment settings
 */
function qw_field_file_attachment_form($field)
{
  $file_styles = qw_all_file_styles();
  ?>
    <!-- file display -->
    <label class="qw-label">Number of items to show:</label>
    <input class="qw-text-short"
           type="text"
           name='<?php print $field['form_prefix']; ?>[file_display_count]'
           value="<?php print ($field['values']['file_display_count']) ? $field['values']['file_display_count']: 0;?>" />

    <p>
      <label class="qw-label">File Display Style:</label>
      <select class='qw-js-title'
              name='<?php print $field['form_prefix']; ?>[file_display_style]'>
        <?php
          foreach($file_styles as $key => $file_style_details)
          {
            $style_selected = ($field['values']['file_display_style'] == $key) ? 'selected="selected"' : '';
            ?>
              <option value="<?php print $key; ?>" <?php print $style_selected; ?>><?php print $file_style_details['description']; ?></option>
            <?php
          }
        ?>
      </select>
    </p>
  <?php
}
