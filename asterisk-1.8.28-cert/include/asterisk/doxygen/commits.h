/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 1999 - 2009, Digium, Inc.
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*!
 * \file
 */

/*!
 * \page CommitMessages Guidelines for Commit Messages
 *
 * \AsteriskTrunkWarning
 *
 * <hr/>
 *
 * \section CommitMsgFormatting Commit Message Formatting
 *
 * The following illustrates the basic outline for commit messages:
 *
  \verbatim
  <One-liner summary of changes>

  <Empty Line> 

  <Verbose description of the changes>

  <Empty Line> 

  <Special Tags>
  \endverbatim
 *
 * Some commit history viewers treat the first line of commit messages as the
 * summary for the commit.  So, an effort should be made to format our commit
 * messages in that fashion.  The verbose description may contain multiple 
 * paragraphs, itemized lists, etc. Always end the first sentence (and any
 * subsequent sentences) with punctuation.
 *
 * Commit messages should be wrapped at 80 %columns.
 *
 * \note For trivial commits, such as "fix the build", or "fix spelling mistake",
 *       the verbose description may not be necessary.
 *
 * <hr/>
 *
 * \section CommitMsgTags Special Tags for Commit Messages
 *
 * \subsection MantisTags Mantis (https://issues.asterisk.org/)
 *
 * To have a commit noted in an issue, use a tag of the form: 
 * \arg (issue #1234)
 *
 * To have a commit automatically close an issue, use a tag of the form:
 * \arg (closes issue #1234)
 *
 * When making a commit for a mantis issue, it is easiest to use the
 * provided commit %message template functionality.  It will format the
 * special tags appropriately, and will also include information about who
 * reported the issue, which patches are being applied, and who did testing.
 * 
 * Assuming that you have bug marshal access (and if you have commit access,
 * it is pretty safe to assume that you do), you will find the commit %message
 * template section directly below the issue details section and above the
 * issue relationships section.  You will have to click the '+' next to
 * "Commit message template" to make the contents of the section visible.
 *
 * Here is an example of what the template will generate for you:
 *
  \verbatim
  (closes issue #1234)
  Reported by: SomeGuy
  Patches:
       fix_bug_1234.diff uploaded by SomeDeveloper (license 5678)
  \endverbatim
 *
 * If the patch being committed was written by the person doing the commit,
 * and is not available to reference as an upload to the issue, there is no
 * need to include something like "fixed by me", as that will be the default
 * assumption when a specific patch is not referenced.
 *
 * \subsection ReviewBoardTags Review Board (https://reviewboard.asterisk.org/)
 *
 * To have a commit set a review request as submitted, include the full URL
 * to the review request.  For example:
 * \arg Review: %https://reviewboard.asterisk.org/r/95/
 *
 * \note The trailing slash in the review URL is required.
 *
 * <hr/>
 *
 * \section CommitMsgSvnmerge Commit Messages with svnmerge
 *
 * When using the svnmerge tool for merging changes between branches, use the
 * commit %message generated by svnmerge.  The '-f' option to svnmerge allows
 * you to specify a file for svnmerge to write out a commit %message to.  The
 * '-F' option to svn commit allows you to specify a file that contains the
 * commit %message.
 *
 * If you are using the expect script wrappers for svnmerge from repotools,
 * a commit %message is automatically placed in the file '../merge.msg'.
 *
 * For more detailed information about working with branches and merging,
 * see the following page on %asterisk.org:
 * \arg http://www.asterisk.org/developers/svn-branching-merging
 */


