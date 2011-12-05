=== Query Wrangler ===
Contributors: daggerhart, forrest.livengood
Tags: query, pages, widget, admin, widgets, administration, manage, views
Requires at least: 3
Tested up to: 3.2.1
Stable tag: trunk

This plugin lets you create new WP queries as pages or widgets. It's basically Drupal Views for Wordpress.

== Description ==

This plugin lets you create new WP queries as pages or widgets. It's basically Drupal Views for WordPress.

Highly based on Drupal's Views, the Query Wrangler's interface is highly intuitive for any Drupal View's user.

This plugin will bring extreme flexibility to WordPress users with it's ability to create custom queries using the WP_Query class. 


== Installation ==

1. Upload `query-wrangler` to the `/wp-content/plugins/` directory
1. Activate the plugin
1. Visit the Query Wrangler Menu to being Creating your custom queries

== Frequently Asked Questions ==

= How do I add Query Pages to my menu? =

The easiest way is to add it as a custom link in the Menus section of your site.

= How do I use query shortcodes? =

Easy, the code you're lookind for looks like this.   [query id=2] , where the number 2 is the query id.

== Screenshots ==

1. Query Wrangler edit screen

== Changelog ==

= 1.2beta3 =

 * Bug fix for empty category and tag pages
 * Bug fix for query shortcodes

= 1.2beta2 =

 * Added shortcodes for inserting any query into a post.

= 1.2beta1 =

 * Added Wordpress page overrides for categories and tags.
 * Fixed query edit page js bug.

= 1.1beta =

 * Bug with canceling forms.  Changed use of jQuery unserializeForm
 
= 1.0beta =

 * Initial Release

== Upgrade Notice ==

1.2beta3  Multiple bug fixes