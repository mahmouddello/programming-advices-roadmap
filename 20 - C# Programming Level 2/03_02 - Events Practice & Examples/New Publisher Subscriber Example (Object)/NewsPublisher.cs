using System;

namespace _03_02___Events_Practice_And_Examples
{
    // This example will show how to pass objects instead of EventsArgs
    public class NewsArticle
    {
        public string Title { get; }
        public string Content { get; }

        public NewsArticle(string title, string content)
        {
            Title = title;
            Content = content;
        }
    }

    public class NewsPublisher
    {
        public event EventHandler<NewsArticle> NewNewsPublished;

        public void PublishNews(string title, string content)
        {
            var Article = new NewsArticle(title, content);
            OnNewsPublished(Article);
        }

        protected virtual void OnNewsPublished(NewsArticle Article)
        {
            // Null safety
            NewNewsPublished?.Invoke(this, Article);
        }
    }

    public class NewsSubscriber
    {
        public string Name { get; }

        public NewsSubscriber(string name)
        {
            Name = name;
        }

        public void Subscribe(NewsPublisher newsPublisher)
        {
            newsPublisher.NewNewsPublished += HandleNewNews;
        }

        public void Unsubscribe(NewsPublisher newsPublisher)
        {
            newsPublisher.NewNewsPublished -= HandleNewNews;
        }

        private void HandleNewNews(object sender, NewsArticle article)
        {
            Console.WriteLine($"{this.Name} Recieved a new article:");
            Console.WriteLine($"\nTitle: {article.Title}");
            Console.WriteLine($"\nContent: {article.Content}");
            Console.WriteLine("\n---------------------\n");
        }
    }

    public class NewsPublisherExample
    {
        static void Main(string[] args)
        {
            NewsPublisher publisher = new NewsPublisher();
            NewsSubscriber subscriber1 = new NewsSubscriber("Mahmoud");
            NewsSubscriber subscriber2 = new NewsSubscriber("Anas");

            subscriber1.Subscribe(publisher); // subscribe to the publisher
            subscriber2.Subscribe(publisher); // subscribe to the publisher

            publisher.PublishNews(
                "ClaudeCode Source Code Leaked (Again)",
                "A small mistake lead to exposing ClaudeCode Source Code (Minified JS file)");

            publisher.PublishNews(
                "New Framework Promises Zero Bugs by Preventing Code Execution",
                "Early adopters report unprecedented stability and equally unprecedented lack of features."
            );

            subscriber1.Unsubscribe(publisher); // unsubscribe, subscriber1 won't be notified

            publisher.PublishNews(
                "AI Code Leak Sparks Debate, Turns Out It's Just Well-Written StackOverflow Answers",
                "Experts confirm 90% similarity with existing online solutions, but unusually clean formatting."
            );

            subscriber2.Unsubscribe(publisher); // unsubscribe, subscriber2 won't be notified

            // Note: No Subcriber, new news won't be printed or notified to anyone
            publisher.PublishNews(
                "Startup Replaces QA Team with AI, Accidentally Ships Feature That Deletes Itself",
                "The feature passed all tests but removed its own functionality upon first user interaction."
            );
        }
    }
}
